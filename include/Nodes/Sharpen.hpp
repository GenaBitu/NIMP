#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution.hpp"

class Sharpen : public KernelConvolution
{
public:
    Sharpen();
    virtual std::string nodeName() override;
};
