#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

class NodeDataImage;

class KernelConvolution : public Node
{
	Q_OBJECT
	Q_DISABLE_COPY(KernelConvolution)
public:
	KernelConvolution();
	virtual std::string nodeName() override;
private:
	int kernelSize;
	float* kernel;
	NodeDataImage* convolve(const std::vector<NodeInput*> inputs);
};

