#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution/Kernel.hpp"

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
	Kernel* kernel;
	NodeDataImage* convolve(const std::vector<NodeInput*> inputs);
};

