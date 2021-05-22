#pragma once

#include <iostream>

template<class T> class Vector {
    public:
        Vector(size_t capacity): capacity_{capacity} {}
        size_t size() const {return size_;}
        void print() const;
        // {
        //     for 
        //     std::cout <<
        // }

        reserve(const int kSize);
        emplace_back(T element);
        pop();
        
        operator[](); // index
        operator+();
        operator*(const T scale); //scalar multiplication
        operator*(const Vector& other_vec); //element-wise multiplication
    private:
        T* vector_;          //
        size_t capacity_ = 1;    // current memory capacity
        size_t size_ = 0;        // current vector size
};

//template<T> reserve(const int kSize)