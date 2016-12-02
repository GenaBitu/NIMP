#include "Nodes/BoxBlur.hpp"

BoxBlur::BoxBlur() : KernelConvolution{3}
{
    kernel->set({1, 1, 1, 1, 1, 1, 1, 1, 1});
    kernel->normalize();
}

std::string BoxBlur::nodeName()
{
    return "Box blur";
}
