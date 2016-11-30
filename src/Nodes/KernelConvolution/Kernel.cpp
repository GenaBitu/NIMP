#include "Nodes/KernelConvolution/Kernel.hpp"

Kernel::Kernel(int size) : Matrix{size} {}

float Kernel::sum()
{
    float sum{0};
    for(int i{0}; i < width; i++)
    {
        for(int j{0}; j < height; j++)
        {
            sum += (*this)[i][j];
        }
    }
    return sum;
}

void Kernel::normalize()
{
    float divisor{sum()};
    for(int i{0}; i < width; i++)
    {
        for(int j{0}; j < height; j++)
        {
            (*this)[i][j] /= divisor;
        }
    }
}
