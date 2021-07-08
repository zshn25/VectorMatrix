#pragma once
// #include <matrix.h>
#include <iostream>
#include <stdexcept>

template<class T> class Vector {
    public:
        // Constructors
    Vector() = default;                                         // default constructor
        Vector(const Vector<T>& another_vector);                // copy constructor
        Vector<T>& operator=(const Vector<T>& another_vector);  // copy assignment
        Vector(const Vector<T>&& another_vector);               // move constructor
        Vector<T>& operator=(const Vector<T>&& another_vector); // move assignment
        Vector(size_t capacity, T initial = T{});               // constructor based on capacity and a default value

        // Destructor
        ~Vector() {delete[] _vector;}
        
        size_t Size() const {return _curr_idx;}
        size_t Capacity() const {return _capacity;}
        // void print() const; // ToDo: write a print fn

        void emplace_back(const T& element);
        // ToDo: Emplace back a whole vector?
        T pop();
        
        // Element read/write access
        T& operator[](const size_t index); // return element reference at index
        const T operator[](const size_t index) const; // to also support const objs

        // Arithmetic
        Vector operator+(Vector<T>& other_vec) const;
        // Vector<T> operator-(const Vector& other_vec) const; 
        Vector operator*=(T scale); //scalar multiplication
        Vector operator*(Vector& other_vec) const; //element-wise multiplication
        // Vector operator*(Matrix<T>& matrix) const; // vector matrix multiplication
    private:
        T* _vector = nullptr;   // pointer to first data element
        size_t _capacity = 0;   // current memory capacity
        size_t _curr_idx = 0;   // current vector size (same as numel)
        
        void Reserve(const size_t capacity);
};

//// Definitions

template<class T>
Vector<T>::Vector(size_t capacity, T initial): _capacity{capacity},
                                 _curr_idx{capacity},
                                 _vector{new T[capacity]{}} // allocate stack and store its pointer
{
    for (size_t i=0; i < capacity; ++i)
        _vector[i] = initial;   // initialize
}

// Copy constructor
template <class T>
Vector<T>::Vector(const Vector<T>& another_vector)
    : _curr_idx(another_vector.Size()),
      _capacity(another_vector.Capacity()),
      _vector(new T[another_vector.Capacity()])
{

    // Copy everything from another vector
    for (size_t i = 0; i < _capacity; ++i)
        _vector[i] = another_vector[i];
}

// Copy assignment
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& another_vector)
{
    delete[] _vector;   // Delete before copying everything from another vector

    // Copy everything from another vector
    _curr_idx = another_vector.Size();
    _capacity = another_vector.Capacity();
    _vector = new T[_capacity];
    for (size_t i=0; i < _capacity; ++i)
        _vector[i] = another_vector[i];

    return *this;
}

// Move constructor
template <class T>
Vector<T>::Vector(const Vector<T>&& another_vector)
    : _curr_idx(another_vector.Size()),
      _capacity(another_vector.Capacity()),
      _vector(another_vector._vector)
{

    // Release other vector's pointer
    another_vector = nullptr;
    another_vector.Size = 0;
    another_vector.Capacity = 0;
}

// Move assignment
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>&& another_vector)
{
    if (this != &another_vector)
    {

        delete[] _vector;   // Delete before moving everything from another vector

        // Copy pointer another vector
        _curr_idx = another_vector.Size();
        _capacity = another_vector.Capacity();
        _vector = another_vector._vector;

        // Release other vector's pointer
        another_vector = nullptr;
        another_vector.Size = 0;
        another_vector.Capacity = 0;

    }
    return *this;
}

////////////////////////////////////////////////////////////

// Memory allocation
template<class T>
inline void Vector<T>::Reserve(const size_t capacity)
{
    // Haandle case when capacity is less than size. (No need to reallocate)
    if (capacity > _curr_idx)
    {
        // Reserves memory of size capacity for the vector_
        T* temp = new T[capacity];

        // Move previous elements to this memory
        for (size_t i=0; i < _capacity; ++i)
            temp[i] = _vector[i];

        delete[] _vector; // Delete old vector
        _capacity = capacity;
        _vector = temp;
    }
}

template<class T>
void Vector<T>::emplace_back(const T& element)
{
    // If no cacacity, increase capacity
    if (_curr_idx == _capacity)
    {
        if (_capacity == 0) // handing initial when 
            Reserve(8);
        else
            Reserve(_capacity*2);
    }

    // Append an element to the array
    _vector[_curr_idx] = element;
    _curr_idx++;
}

template<class T>
T Vector<T>::pop()
{   
    if (_curr_idx > 0)  // Nothing to pop otherwise
    {
        T to_return = _vector[_curr_idx-1]; // store return value before deleting
        // vector_[curr_idx_-1]->~T();         // delete from memory
        _curr_idx--;

        return to_return;
    }
    else
        throw std::out_of_range("Nothing to pop")
}

// Element read/write access
template<class T>
T& Vector<T>::operator[](const size_t index)
{
    if (index >= _curr_idx)
        throw std::invalid_argument("Index must be less than vector's size");
    
    return _vector[index];
}

template<class T>
const T Vector<T>::operator[](const size_t index) const
{
    if (index >= _curr_idx)
        throw std::invalid_argument("Index must be less than vector's size");
    
    return _vector[index];
}

// Vector arithmetic operators
template<class T>
Vector<T> Vector<T>::operator+(Vector<T>& other_vector) const
{
    if (other_vector.Size() == _curr_idx)   // vectors size must be same for element-wise add
    {
        Vector<T> temp_vector(_curr_idx);
        for (size_t i=0; i<_curr_idx; ++i)
        {
            temp_vector[i] = _vector[i] + other_vector[i];
        }
        return temp_vector;
    }
}

// Scalar multiplication
template<class T>
Vector<T> Vector<T>::operator*=(T scalar)
{
    for (size_t i=0; i<_curr_idx; ++i)
        _vector[i] *= scalar;
    return *this;
}

// Element-wise multiplication
template<class T>
Vector<T> Vector<T>::operator*(Vector<T>& other_vector) const
{
    if (other_vector.Size() == _curr_idx)   // vectors size must be same for element-wise add
    {
        Vector<T> temp_vector(_curr_idx);
        for (size_t i=0; i<_curr_idx; ++i)
        {
            temp_vector[i] = _vector[i] * other_vector[i];
        }
        return temp_vector;
    }
}
