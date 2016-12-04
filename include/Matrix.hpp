#pragma once

#include "Global.hpp"

#include "RowSelector.hpp"

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Matrix;

template<typename T>
void swap(Matrix<T>& first, Matrix<T>& second);

template<typename T, typename>
class Matrix
{
public:
    Matrix(int size);
    Matrix(int width, int height);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix other);
	friend void swap<T>(Matrix& first, Matrix& second);
	int getWidth();
	int getHeight();
    RowSelector<Matrix<T>, T> operator[](int index);
protected:
	friend RowSelector<Matrix<T>, T>;
	T* data;
private:
	int width;
	int height;
};

#include "src/Matrix.tpp"
