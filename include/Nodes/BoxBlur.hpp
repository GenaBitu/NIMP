#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution.hpp"

class BoxBlur : public KernelConvolution
{
public:
    BoxBlur();
    virtual std::string nodeName() override;
};
