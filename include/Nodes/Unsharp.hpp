#pragma once

#include "Global.hpp"

#include "Nodes/KernelConvolution.hpp"

class Unsharp : public KernelConvolution
{
public:
    Unsharp();
    virtual std::string nodeName() override;
};
