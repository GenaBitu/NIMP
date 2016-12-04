#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution/Kernel.hpp"

#include "NodeSystem/Node.hpp"

class NodeDataImage;

class KernelConvolution : public Node
{
public:
	KernelConvolution(int kernelSize = 3);
	KernelConvolution(const KernelConvolution& other);
	KernelConvolution(KernelConvolution&& other);
	KernelConvolution& operator=(const KernelConvolution& other);
	KernelConvolution& operator=(KernelConvolution&& other);
	friend void swap(KernelConvolution& first, KernelConvolution& second);
protected:
	Kernel* kernel;
private:
	NodeDataImage* convolve(const std::vector<NodeInput*> inputs);
};

