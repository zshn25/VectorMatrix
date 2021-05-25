#pragma once

#include <iostream>

template<class T> class Vector {
    public:
        Vector(size_t capacity): capacity_{capacity},
                                 curr_idx_{capacity},
                                 vector_{new T[capacity]} {}
        size_t size() const {return curr_idx_;}
        size_t capacity() const {return capacity_;}
        // void print() const;

        void reserve(const size_t capacity);
        void emplace_back(const T& element);
        T pop();
        
        T& operator()(const size_t index); // index
        Vector<T> operator+(const Vector<T>& other_vec) const;
        Vector operator-(const Vector& other_vec) const; 
        Vector operator*(const T scale) const; //scalar multiplication
        Vector operator*(const Vector& other_vec) const; //element-wise multiplication
        // implementing in matrix class 
        // Vector operator*(const Matrix& matrix) const; // vector matrix multiplication
    private:
        T* vector_ = new T[1];   // data
        size_t capacity_ = 1;    // current memory capacity
        size_t curr_idx_ = 0;        // current vector size
};
