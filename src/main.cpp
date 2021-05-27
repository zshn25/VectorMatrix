#include <vector.h>
#include <iostream>
// #include <matrix.h>

using std::cout;
using std::endl;

int main()
{
    {
        Vector<float> vector(1);    // construct
        vector[0] = 1.0f;           // read/write access
        vector.emplace_back(2.0f);  // add element
        float b = vector.pop();     // remove element
        vector.emplace_back(1.0f);
        vector.emplace_back(1.0f);
        for (size_t i=0;i<3;++i)
            cout << vector[i] << ", ";
        cout << endl;

        Vector<float> another_vec(3);
        for (size_t i=0;i<3;++i)
        {
            another_vec[i] = 2.0f;
            cout << another_vec[i] << ", ";
        }

        Vector<float> sum = vector + another_vec;
        for (size_t i=0;i<3;++i)
            cout << sum[i] << ", ";
        cout << endl;
    }                               // destruct

    cout << "Checking destructor" << endl;

    return 0;
}