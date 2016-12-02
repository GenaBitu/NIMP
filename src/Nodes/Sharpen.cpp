#include "Nodes/Sharpen.hpp"

Sharpen::Sharpen() : KernelConvolution{3}
{
    kernel->set({0, -1, 0, -1, 5, -1, 0, -1, 0});
}

std::string Sharpen::nodeName()
{
    return "Sharpen";
}
