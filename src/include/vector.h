#pragma once
// #include <matrix.h>
#include <iostream>
#include <stdexcept>

template<class T> class Vector {
    public:
        // Constructors
        Vector() = default;
        Vector(const Vector<T>& another_vector);    // copy constructor
        Vector<T>& operator=(const Vector<T> &);    // copy assignment
        // Vector(size_t capacity);    
        Vector(size_t capacity, T initial = T{});   // based on capacity

        // Destructor
        ~Vector() {delete[] vector_;}
        
        // ToDo: Implement copy, assignment constructors
        size_t size() const {return curr_idx_;}
        size_t capacity() const {return capacity_;}
        // void print() const; // ToDo

        void reserve(const size_t capacity);
        void emplace_back(const T& element);
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
        T* vector_ = nullptr;   // pointer to first data element
        size_t capacity_ = 0;   // current memory capacity
        size_t curr_idx_ = 0;   // current vector size (same as numel)
};

// Constructors
// template<class T>
// Vector<T>::Vector(size_t capacity): capacity_{capacity},
//                                  curr_idx_{capacity},
//                                  vector_{new T[capacity]{}} // allocate stack and store its pointer
// {
//     for (size_t i=0; i < capacity; ++i)
//         vector_[i] = T{};   // initialize
// }

template<class T>
Vector<T>::Vector(size_t capacity, T initial): capacity_{capacity},
                                 curr_idx_{capacity},
                                 vector_{new T[capacity]{}} // allocate stack and store its pointer
{
    for (size_t i=0; i < capacity; ++i)
        vector_[i] = initial;   // initialize
}

// Copy constructor
template<class T>
Vector<T>::Vector(const Vector<T>& another_vector)
{
    delete[] vector_;   // Delete before copying everything from another vector

    // Copy everything from another vector
    curr_idx_ = another_vector.size();
    capacity_ = another_vector.capacity();
    vector_ = new T[capacity_];
    for (size_t i=0; i < capacity_; ++i)
        vector_[i] = another_vector[i];
}

// Copy assignment
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& another_vector)
{
    delete[] vector_;   // Delete before copying everything from another vector

    // Copy everything from another vector
    curr_idx_ = another_vector.size();
    capacity_ = another_vector.capacity();
    vector_ = new T[capacity_];
    for (size_t i=0; i < capacity_; ++i)
        vector_[i] = another_vector[i];

    return *this;
}

// Memory allocation
template<class T>
inline void Vector<T>::reserve(const size_t capacity)
{
    // Haandle case when capacity is less than size. (No need to reallocate)
    if (capacity > curr_idx_)
    {
        // Reserves memory of size capacity for the vector_
        T* temp = new T[capacity];

        // Move previous elements to this memory
        for (size_t i=0; i < capacity_; ++i)
            temp[i] = vector_[i];

        delete[] vector_; // Delete old vector
        capacity_ = capacity;
        vector_ = temp;
    }
}

template<class T>
void Vector<T>::emplace_back(const T& element)
{
    // If no cacacity, increase capacity
    if (curr_idx_ == capacity_)
    {
        if (capacity_ == 0) // handing initial when 
            reserve(8);
        else
            reserve(capacity_*2);
    }

    // Append an element to the array
    vector_[curr_idx_] = element;
    curr_idx_++;
}

template<class T>
T Vector<T>::pop()
{   
    if (curr_idx_ > 0)  // Nothing to pop otherwise
    {
        T to_return = vector_[curr_idx_-1]; // store return value before deleting
        // vector_[curr_idx_-1]->~T();         // delete from memory
        curr_idx_--;

        return to_return;
    }
    else
        throw std::out_of_range("Nothing to pop")
}

// Element read/write access
template<class T>
T& Vector<T>::operator[](const size_t index)
{
    if (index >= curr_idx_)
        throw std::invalid_argument("Index must be less than vector's size");
    
    return vector_[index];
}

template<class T>
const T Vector<T>::operator[](const size_t index) const
{
    if (index >= curr_idx_)
        throw std::invalid_argument("Index must be less than vector's size");
    
    return vector_[index];
}

// Vector arithmetic operators
template<class T>
Vector<T> Vector<T>::operator+(Vector<T>& other_vector) const
{
    if (other_vector.size() == curr_idx_)   // vectors size must be same for element-wise add
    {
        Vector<T> temp_vector(curr_idx_);
        for (size_t i=0; i<curr_idx_; ++i)
        {
            temp_vector[i] = vector_[i] + other_vector[i];
        }
        return temp_vector;
    }
}

// Scalar multiplication
template<class T>
Vector<T> Vector<T>::operator*=(T scalar)
{
    for (size_t i=0; i<curr_idx_; ++i)
        vector_[i] *= scalar;
    return *this;
}

// Element-wise multiplication
template<class T>
Vector<T> Vector<T>::operator*(Vector<T>& other_vector) const
{
    if (other_vector.size() == curr_idx_)   // vectors size must be same for element-wise add
    {
        Vector<T> temp_vector(curr_idx_);
        for (size_t i=0; i<curr_idx_; ++i)
        {
            temp_vector[i] = vector_[i] * other_vector[i];
        }
        return temp_vector;
    }
}
