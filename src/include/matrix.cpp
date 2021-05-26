#include <matrix.h>

template<class T>
T* Matrix<T>::operator()(size_t i, size_t j)
{
    return matrix_[i * mCols + j];
}