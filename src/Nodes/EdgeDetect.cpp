#include "Nodes/EdgeDetect.hpp"

EdgeDetect::EdgeDetect() : KernelConvolution{3}
{
    kernel->set({-1, -1, -1, -1, 8, -1, -1, -1, -1});
}

std::string EdgeDetect::nodeName()
{
    return "Detect edges";
}
