#pragma once

#include "../Global.hpp"

template<class T, class U>
class RowSelector
{
private:
    friend T;
    T* nodeData;
    int row, width;
    RowSelector(T* nodeData, int row, int width);
    U& operator[](int index);
};

#include "../../src/NodeSystem/RowSelector.tpp"
