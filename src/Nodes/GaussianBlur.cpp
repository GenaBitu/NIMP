#include "Nodes/GaussianBlur.hpp"

GaussianBlur::GaussianBlur() : KernelConvolution{3}
{
    kernel->set({1, 2, 1, 2, 4, 2, 1, 2, 1});
    kernel->normalize();
}

std::string GaussianBlur::nodeName()
{
    return "Gaussian blur";
}
