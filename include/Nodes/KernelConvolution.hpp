#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution/Kernel.hpp"

#include "NodeSystem/Node.hpp"

class NodeDataImage;

class KernelConvolution : public Node
{
public:
	KernelConvolution(int kernelSize);
protected:
	Kernel* kernel;
private:
	NodeDataImage* convolve(const std::vector<NodeInput*> inputs);
};

