#include "Nodes/KernelConvolution.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputImage.hpp"

KernelConvolution::KernelConvolution() : kernel{new Kernel{3}}
{
	inputs.push_back(new NodeInputImage{this, "Image"});
	outputs.push_back(new NodeOutputImage{this, "Image"});
    relations.push_back(std::bind(&KernelConvolution::convolve, this, std::placeholders::_1));
	(*kernel)[0][0] = 1;
	(*kernel)[0][1] = 2;
	(*kernel)[0][2] = 1;
	(*kernel)[1][0] = 2;
	(*kernel)[1][1] = 4;
	(*kernel)[1][2] = 2;
	(*kernel)[2][0] = 1;
	(*kernel)[2][1] = 2;
	(*kernel)[2][2] = 1;
	kernel->normalize();
}

std::string KernelConvolution::nodeName()
{
	return "Kernel Convolution";
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
	int offset{kernel->width / 2};
    for(int i{1}; i < input->width - 1; i++)
	{
		for(int j{1}; j < input->height - 1; j++)
		{
			(*output)[i][j].r = 0;
			(*output)[i][j].g = 0;
			(*output)[i][j].b = 0;
			for(int k{0}; k < kernel->width; k++)
			{
				for(int l{0}; l < kernel->height; l++)
				{
					//qDebug() << (*kernel)[k][l];
					(*output)[i][j].r += (*input)[i - offset + k][j - offset + l].r * (*kernel)[k][l];
					(*output)[i][j].g += (*input)[i - offset + k][j - offset + l].g * (*kernel)[k][l];
					(*output)[i][j].b += (*input)[i - offset + k][j - offset + l].b * (*kernel)[k][l];
				}
			}
		}
	}
	return output;
}
