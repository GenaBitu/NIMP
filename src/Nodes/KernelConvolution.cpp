#include "Nodes/KernelConvolution.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputImage.hpp"

KernelConvolution::KernelConvolution(int kernelSize) : kernel{new Kernel{kernelSize}}
{
	inputs.push_back(new NodeInputImage{this, "Image"});
	outputs.push_back(new NodeOutputImage{this, "Image"});
    relations.push_back(std::bind(&KernelConvolution::convolve, this, std::placeholders::_1));
}

KernelConvolution::KernelConvolution(const KernelConvolution& other) : KernelConvolution{other.kernel->getWidth()}
{
	kernel = new Kernel{*(other.kernel)};
}

KernelConvolution::KernelConvolution(KernelConvolution&& other) : KernelConvolution{}
{
	swap(*this, other);
}

KernelConvolution& KernelConvolution::operator=(const KernelConvolution& other)
{
	if(this != &other)
	{
		delete kernel;
		kernel = new Kernel{*(other.kernel)};
	}
	return *this;
}

KernelConvolution& KernelConvolution::operator=(KernelConvolution&& other)
{
	swap(*this, other);
	return *this;
}

void swap(KernelConvolution& first, KernelConvolution& second)
{
	using std::swap;
	swap(static_cast<Node&>(first), static_cast<Node&>(second));
	swap(first.kernel, second.kernel);
}

NodeDataImage* KernelConvolution::convolve(const std::vector<NodeInput*> inputs)
{
	NodeDataImage* input{dynamic_cast<NodeDataImage*>(inputs[0]->getData())};
	NodeDataImage* output{new NodeDataImage{input->width, input->height}};
	if(input == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
	int offset{kernel->getWidth() / 2};
    for(int i{0}; i < input->width; i++)
	{
		for(int j{0}; j < input->height; j++)
		{
			(*output)[i][j].r = 0;
			(*output)[i][j].g = 0;
			(*output)[i][j].b = 0;
			(*output)[i][j].a = (*input)[i][j].a;
			for(int k{0}; k < kernel->getWidth(); k++)
			{
				for(int l{0}; l < kernel->getHeight(); l++)
				{
                    int x{i - offset + k};
                    int y{j - offset + l};
					if(x < 0) {x = 0;}
					if(x >= input->width) {x = input->width - 1;}
					if(y < 0) {y = 0;}
					if(y >= input->height) {y = input->height - 1;}
					(*output)[i][j].r += (*input)[x][y].r * (*kernel)[k][l];
					(*output)[i][j].g += (*input)[x][y].g * (*kernel)[k][l];
					(*output)[i][j].b += (*input)[x][y].b * (*kernel)[k][l];
				}
			}
		}
	}
	delete input;
	return output;
}
