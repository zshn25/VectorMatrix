#pragma once

#include <vector.h>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), matrix_(Vector<T>(rows * cols)) {}

        size_t rows() const {return rows_;}
        size_t cols() const {return cols_;}

        T& operator()(const size_t i, const size_t j);
        const T operator()(const size_t i, const size_t j) const; // to also support const objs
        static Vector<T> dot(Vector<T> vector, Matrix<T> matrix); //vector matrix multiplication
    private:
        Vector<T> data_; // data
        size_t rows_;
        size_t cols_;
};

template<class T>
T& Matrix<T>::operator()(const size_t i, const size_t j)
{
    return data_[i*cols + j];
}

template<class T>
const T Matrix<T>::operator()(const size_t i, const size_t j) const
{
    return data_[i*cols + j];
}

// Vector matrix multiplication
template<class T>
static Vector<T> Matrix<T>::dot(Vector<T> vector, Matrix<T> matrix)
{
    if (matrix.rows() == curr_idx_)   // vectors size must be same for element-wise add
    {
        Vector<T> temp_vector(matrix.cols());
        for (size_t i=0; i<matrix.cols(); ++i)
            temp_vector[i] = 0;     // Initialize with 0

        for (size_t j=0; j < matrix.cols(); ++j)
        {
            for (size_t i=0; i<curr_idx_; ++i)
            {
                temp_vector[j] += vector[i] * matrix(i,j);
            }
        }
        return temp_vector;
    }
}