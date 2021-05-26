#pragma once

// #include <iostream>

template<class T> class Vector {
    public:
        // Constructors
        Vector() = default;
        Vector(size_t capacity);    // based on capacity

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
        
        // // Arithmetic
        Vector<T> operator+(const Vector<T>& other_vec) const;
        // Vector<T> operator-(const Vector& other_vec) const; 
        // Vector<T> operator*(const T scale) const; //scalar multiplication
        // Vector<T> operator*(const Vector& other_vec) const; //element-wise multiplication
        // implementing in matrix class 
        // Vector operator*(const Matrix& matrix) const; // vector matrix multiplication
    private:
        T* vector_ = nullptr;   // pointer to first data element
        size_t capacity_ = 0;   // current memory capacity
        size_t curr_idx_ = 0;   // current vector size (same as numel)
};

// Constructors
template<class T>
Vector<T>::Vector(size_t capacity): capacity_{capacity},
                                 curr_idx_{capacity},
                                 vector_{new T[capacity]} // allocate
{
    for (size_t i=0; i < capacity; ++i)
        vector_[i] = T{};   // initialize
}

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
        {
            temp[i] = vector_[i];
        }

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
        reserve(capacity_*2);   

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
}

// Element read/write access
template<class T>
T& Vector<T>::operator[](const size_t index)
{
    if (index < curr_idx_)
        return vector_[index];
}

// Vector arithmetic operators
template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other_vector) const
{
    Vector<T> temp_vector = Vector(curr_idx_);
    for (size_t i=0; i<curr_idx_; ++i)
    {
        temp_vector[i] = vector_[i] + other_vector[i];
    }
    return temp_vector;
}
