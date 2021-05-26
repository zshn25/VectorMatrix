#include <vector.h>

// Constructors
template<class T>
Vector<T>::Vector(size_t capacity): capacity_{capacity},
                                 curr_idx_{capacity},
                                 vector_{new T[capacity]} {}

template<class T>
void Vector<T>::reserve(const size_t capacity)
{
    // Reserves memory of size capacity for the vector_
    T* temp = new T[capacity];

    // ToDo: Haandle case when capacity is less than size. (No need to reallocate)

    // Move previous elements to this memory
    for (int i=0; i < this->capacity_; ++i)
    {
        temp[i] = vector_[i];
    }

    delete[] vector_; // Delete old vector
    capacity_ = capacity;
    vector_ = temp;
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
        vector_[curr_idx_-1]->~T();         // delete from memory
        curr_idx_--;

        return to_return;
    }
    
}

template<class T>
T& Vector<T>::operator()(const size_t index)
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
