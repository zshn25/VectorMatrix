#pragma once

#include <iostream>

template<class T> class Vector {
    public:
        // Constructors
        Vector(size_t capacity);    // based on capacity
        // ToDo: Implement copy, assignment constructors
        size_t size() const {return curr_idx_;}
        size_t capacity() const {return capacity_;}
        // void print() const; // ToDo

        void reserve(const size_t capacity);
        void emplace_back(const T& element);
        T pop();
        
        T& operator()(const size_t index); // index
        Vector<T> operator+(const Vector<T>& other_vec) const;
        Vector<T> operator-(const Vector& other_vec) const; 
        Vector<T> operator*(const T scale) const; //scalar multiplication
        Vector<T> operator*(const Vector& other_vec) const; //element-wise multiplication
        // implementing in matrix class 
        // Vector operator*(const Matrix& matrix) const; // vector matrix multiplication
    private:
        T* vector_ = nullptr;   // pointer to first data element
        size_t capacity_ = 0;    // current memory capacity
        size_t curr_idx_ = 0;        // current vector size (same as numel)
};
