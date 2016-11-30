#include "Nodes/KernelConvolution/Kernel.hpp"

Kernel::Kernel(int size) : Matrix{size} {}

Kernel::Kernel(int size, std::initializer_list<float> list) : Kernel{size}
{
    set(list);
}

void Kernel::set(std::initializer_list<float> list)
{
    int i{0};
    for(std::initializer_list<float>::iterator it{list.begin()}; it != list.end(); it++)
    {
        if(i >= width * height)
        {
            break;
        }
        data[i] = *it;
        i++;
    }
}

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
    if(std::abs(divisor) > 0.001)
    {
        for(int i{0}; i < width; i++)
        {
            for (int j{0}; j < height; j++) {
                (*this)[i][j] /= divisor;
            }
        }
    }
}
