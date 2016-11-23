#pragma once

#include "Global.hpp"

#include "NodeSystem/Node.hpp"

class KernelConv : public Node
{
	Q_OBJECT
	Q_DISABLE_COPY(KernelConv)
public:
	KernelConv();
	virtual std::string nodeName() override;
private:
	int kernelSize;
	float* kernel;
};

