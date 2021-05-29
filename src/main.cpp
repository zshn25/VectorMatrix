#include <vector.h>
#include <iostream>
#include <matrix.h>

using std::cout;
using std::endl;

int main()
{
    {
        // Initialize vector
        Vector<float> vector(3, 1.0f);    // construct vector of size 3 with value 1
        
        for (size_t i=0;i<3;++i)
            cout << vector[i] << ", ";
        cout << endl;

        // Initialize matrix
        Matrix<float> matrix(3,4);      // 3x4 matrix
        for (size_t i=0;i<3;++i)
            for (size_t j=0;j<4;++j)
                matrix(i,j)=10.f;   // all entries with value 10
        
        // Vector matrix multiplication
        Vector<float>dot_product = vector * matrix;
        for (size_t i=0;i<4;++i)
            cout << dot_product[i] << ", "; // should be vector of size 4 with all entries 30
        cout << endl;

    }                               // destruct

    cout << "Done!" << endl;

    return 0;
}