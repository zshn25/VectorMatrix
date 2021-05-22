#pragma once

#include <vector.h>

template<class T> class Matrix {
    public:
        Matrix(size_t rows, size_t cols)
            : rows_(rows), cols_(cols), matrix_(rows * cols) {}
        void shape const (); // print shape
    private:
        Vector<T> matrix_;           // data
        size_t rows_;
        size_t cols_;
};

