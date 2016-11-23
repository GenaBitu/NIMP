#include "Nodes/KernelConvolution.hpp"

#include "NodeSystem/NodeInputTypes/NodeInputImage.hpp"
#include "NodeSystem/NodeOutputTypes/NodeOutputImage.hpp"

KernelConvolution::KernelConvolution() : kernelSize{3}, kernel{new float[9]}
{
	inputs.push_back(new NodeInputImage{this, "Image"});
	outputs.push_back(new NodeOutputImage{this, "Image"});
    relations.push_back(std::bind(&KernelConvolution::convolve, this, std::placeholders::_1));
}

std::string KernelConvolution::nodeName()
{
	return "Kernel Convolution";
}

NodeDataImage* KernelConvolution::convolve(const std::vector<NodeInput*>* const inputs)
{
	NodeDataImage* input{dynamic_cast<NodeDataImage*>((*inputs)[0]->getData())};
	if(input == nullptr)
	{
		// TODO: DIE HORRIBLY IN FLAMES
		return nullptr;
	}
}
