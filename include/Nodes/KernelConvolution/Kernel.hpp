#pragma once

#include "Global.hpp"

#include "Matrix.hpp"

class Kernel : public Matrix<float>
{
public:
    Kernel(int size);
    Kernel(int size, std::initializer_list<float> list);
    void set(std::initializer_list<float> list);
    float sum();
    void normalize();
};
