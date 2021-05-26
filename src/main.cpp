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
    }                               // destruct

    cout << "Checking destructor" << endl;

    return 0;
}