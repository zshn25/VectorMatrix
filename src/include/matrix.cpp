#include <matrix.h>

T Matrix::operator()(size_t i, size_t j)
{
    return mData[i * mCols + j];
}