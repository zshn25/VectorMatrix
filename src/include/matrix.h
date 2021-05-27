#pragma once

#include <vector.h>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), matrix_(Vector<T>(rows * cols)) {}

        size_t rows() const {return rows_;}
        size_t cols() const {return cols_;}

        T& operator[](const size_t i, const size_t j);
        // static Vector<T> operator*(Vector vector, Matrix matrix); //vector matrix multiplication
    private:
        *T matrix_; // data
        size_t rows_;
        size_t cols_;
};

