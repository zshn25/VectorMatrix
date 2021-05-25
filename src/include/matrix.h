#pragma once

#include <vector.h>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), matrix_(Vector(rows * cols)) {}
        void shape const () {}

        Vector<T> operator()(size_t i, size_t j) const;
        static Vector<T> operator*(Vector vector, Matrix matrix); //vector matrix multiplication
    private:
        Vector<T> matrix_;           // data
        size_t rows_;
        size_t cols_;
};

