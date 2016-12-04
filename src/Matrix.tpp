#include "Matrix.hpp"

template<typename T, typename U>
Matrix<T, U>::Matrix(int size) : Matrix{size, size} {}

template<typename T, typename U>
Matrix<T, U>::Matrix(int width, int height) : data{new T[width * height]{0}}, width{width}, height{height} {}

template<typename T, typename U>
Matrix<T, U>::Matrix(const Matrix& other) : data{new T[width * height]{}}, width{other.width}, height{other.height}
{
	std::copy(other.data, other.data + (width * height), data);
}

template<typename T, typename U>
Matrix<T, U>::Matrix(Matrix&& other) : Matrix{}
{
	swap(*this, other);
}

template<typename T, typename U>
Matrix<T, U>& Matrix<T, U>::operator=(Matrix other)
{
	swap(*this, other);
	return *this;
}

template<typename T>
void swap(Matrix<T>& first, Matrix<T>& second)
{
	using std::swap;
	swap(first.width, second.width);
	swap(first.height, second.height);
	swap(first.data, second.data);
}

template<typename T, typename U>
int Matrix<T, U>::getWidth()
{
	return width;
}

template<typename T, typename U>
int Matrix<T, U>::getHeight()
{
	return height;
}

template<typename T, typename U>
RowSelector<Matrix<T>, T> Matrix<T, U>::operator[](int index)
{
    return RowSelector<Matrix<T, U>, T>{this, index, width};
}
