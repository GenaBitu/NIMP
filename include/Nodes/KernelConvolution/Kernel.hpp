#pragma once

#include "Global.hpp"

#include "Matrix.hpp"

class Kernel : public Matrix<float>
{
public:
    Kernel(int size);
    float sum();
    void normalize();
};
