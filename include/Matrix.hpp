#pragma once

#include "Global.hpp"

#include "RowSelector.hpp"

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Matrix
{
public:
    Matrix(int size);
    Matrix(int width, int height);
    const int width;
    const int height;
    RowSelector<Matrix<T>, T> operator[](int index);
protected:
    friend RowSelector<Matrix<T>, T>;
    T* data;
};

#include "src/Matrix.tpp"
