#pragma once

#include "Global.hpp"

template<class T, class U>
class RowSelector
{
public:
    U& operator[](int index);
private:
    friend T;
    T* matrix;
    int row, width;
    RowSelector(T* matrix, int row, int width);
};

#include "src/RowSelector.tpp"
