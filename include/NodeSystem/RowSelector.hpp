#pragma once

#include "Global.hpp"

template<class T, class U>
class RowSelector
{
public:
    U& operator[](int index);
private:
    friend T;
    T* nodeData;
    int row, width;
    RowSelector(T* nodeData, int row, int width);
};

#include "../../src/NodeSystem/RowSelector.tpp"
