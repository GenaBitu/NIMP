#include "Matrix.hpp"

template<typename T, typename U>
Matrix<T, U>::Matrix(int size) : Matrix{size, size} {}

template<typename T, typename U>
Matrix<T, U>::Matrix(int width, int height) : width{width}, height{height}, data{new T[width * height]{0}} {}

template<typename T, typename U>
RowSelector<Matrix<T>, T> Matrix<T, U>::operator[](int index)
{
    return RowSelector<Matrix<T, U>, T>{this, index, width};
}
