#include <matrix.h>

Matrix::Matrix(size_t rows, size_t cols)
: rows_(rows), cols_(cols), matrix_(rows*cols) {}