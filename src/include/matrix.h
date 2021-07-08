#pragma once

#include <iostream>
#include <vector.h>
#include <type_traits>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), data_(Vector<T>(rows * cols)) {}

        size_t rows() const {return rows_;}
        size_t cols() const {return cols_;}

        T& operator()(const size_t i, const size_t j);
        const T operator()(const size_t i, const size_t j) const; // to also support const objs
        // static Vector<T> dot(Vector<T> vector, Matrix<T> matrix); //vector matrix multiplication
    private:
        Vector<T> data_; // data
        size_t rows_;
        size_t cols_;

        static_assert(std::is_arithmetic<T>::value, "Type must be numeric");
};

template<class T>
T& Matrix<T>::operator()(const size_t i, const size_t j)
{
    return data_[i*cols_ + j];
}

template<class T>
const T Matrix<T>::operator()(const size_t i, const size_t j) const
{
    return data_[i*cols_ + j];
}

// Vector matrix multiplication
template<class T>
inline Vector<T> operator*(Vector<T> vector, Matrix<T> matrix)
{
    // this function is only for numeric types
    static_assert(std::is_arithmetic<T>::value, "Type must be numeric");

    if (matrix.rows() != vector.Size())   // vectors size must be same for element-wise add
        throw std::length_error("Matrix rows should be of same size as the vector");

    // Initialize the return vector
    Vector<T> temp_vector(matrix.cols());
    for (size_t i=0; i<matrix.cols(); ++i)
        temp_vector[i] = 0;     // Initialize with 0

    // Compute dot product
    for (size_t j=0; j < matrix.cols(); ++j)
        for (size_t i=0; i<matrix.rows(); ++i)
            temp_vector[j] += vector[i] * matrix(i,j);

    return temp_vector;
}

// Matrix vector multiplication
template<class T>
inline Vector<T> operator*(Matrix<T> matrix, Vector<T> vector)
{
    static_assert(std::is_arithmetic<T>::value, "Type must be numeric");// this function is only for numeric types
    if (matrix.cols() != vector.Size())   // vectors size must be same for element-wise add
        throw std::length_error("Matrix columns should be of same size as the vector");

    // Initialize the return vector
    Vector<T> temp_vector(matrix.rows());
    for (size_t i=0; i<matrix.rows(); ++i)
        temp_vector[i] = 0;     // Initialize with 0

    // Compute dot product
    for (size_t i=0; i<matrix.rows(); ++i)
        for (size_t j=0; j < matrix.cols(); ++j)
            temp_vector[i] += matrix(i,j) * vector[j];

    return temp_vector;

}