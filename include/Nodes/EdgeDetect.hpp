#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution.hpp"

class EdgeDetect : public KernelConvolution
{
public:
    EdgeDetect();
    virtual std::string nodeName() override;
};
