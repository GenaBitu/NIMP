#include "Nodes/Unsharp.hpp"

Unsharp::Unsharp() : KernelConvolution{5}
{
    kernel->set({1, 4, 6, 4, 1, 4, 16, 24, 16, 4, 6, 24, -476, 24, 6, 4, 16, 24, 16, 4, 1, 4, 6, 4, 1});
    kernel->normalize();
}

std::string Unsharp::nodeName()
{
    return "Unsharp mask";
}
