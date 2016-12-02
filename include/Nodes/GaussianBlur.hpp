#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution.hpp"

class GaussianBlur : public KernelConvolution
{
public:
    GaussianBlur();
    virtual std::string nodeName() override;
};
