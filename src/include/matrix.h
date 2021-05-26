#pragma once

#include <vector.h>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), matrix_(Vector(rows * cols)) {}

        T* operator()(size_t i, size_t j);
        // static Vector<T> operator*(Vector vector, Matrix matrix); //vector matrix multiplication
    private:
        T* matrix_ = new T[1];           // data
        size_t rows_;
        size_t cols_;
};

