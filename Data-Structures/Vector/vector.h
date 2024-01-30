#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>

class Vector {
private:
    int size_;
    int capacity_;
    T* data_;

public:

    /* Member Funtions */

    // Default Constructor
    Vector() : size_(0), capacity_(1), data_(new T[capacity_]) {}
    // Overloaded Constructor
    Vector(size_t capacity) : size_(0), capacity_(capacity), data_(new T[capacity_]) {}
    //Copy Constructor
    Vector(const Vector& other): size_(other.size_), capacity_(other.capacity_), data_(new T[capacity_]) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
    // Destructor
    ~Vector() { 
        delete[] data_; 
    }
    // Assignment Operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            std::copy(other.data_, other.data_ + other.size_, data_);
        }
        return *this;
    }

    // Iterators
    T* begin() { 
        return data_; 
    }

    T* end() { 
        return data_ + size_; 
    }

    T* cbegin() const { 
        return data_; 
    }

    T* cend() const { 
        return data_ + size_; 
    }

    T* rbegin() { 
        return data_ + size_ - 1; 
    }

    T* rend() { 
        return data_ - 1; 
    }

    T* crbegin() const { 
        return data_ + size_ - 1; 
    }

    T* crend() const { 
        return data_ - 1; 
    }

    // Capacity
    int size() const { 
        return size_; 
    }

    int max_size() const { 
        max = (pow(2, 32)/sizeof(T)) - 1;
        return max;
    }

    int capacity() const { 
        return capacity_; 
    }

    bool empty() const { 
        return size_ == 0; 
    }

    void resize(int n) {
        if (n > capacity_) {
            reserve(n);
        }
        size_ = n;
    }

    void reserve(int n) {
        if (n > capacity_) {
            T* temp = new T[n];
            std::copy(data_, data_ + size_, temp);
            delete[] data_;
            data_ = temp;
            capacity_ = n;
        }
    }

    void shrink_to_fit() {
        if (size_ < capacity_) {
            T* temp = new T[size_];
            std::copy(data_, data_ + size_, temp);
            delete[] data_;
            data_ = temp;
            capacity_ = size_;
        }
    }

    // Element Access
    T& operator[](int i) const{ // Assumes user will not go out of bounds
        return data_[i];
    }

    T& at(int i) const{
        if (i < 0 || i >= size_) { // Assumes user will go out of bounds
            throw std::out_of_range("Index out of range");
        }
        return data_[i];
    }

    T& front() { 
        return data_[0]; 
    }

    T& back() { 
        return data_[size_ - 1]; 
    }

    T* data() { 
        return data_; 
    }

    // Modifiers
    void assign(int n, const T& val) {
        if (n > capacity_) {
            reserve(n);
        }
        size_ = n;
        std::fill(data_, data_ + size_, val);
    }

    void push_back(const T& val) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        data_[size_] = val;
        size_++;
    }

    void pop_back() {
        size_--;
    }

    void insert(int i, const T& val) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        for (int j = size_; j > i; j--) {
            data_[j] = data_[j - 1];
        }
        data_[i] = val;
        size_++;
    }

    void erase(int i) {
        for (int j = i; j < size_ - 1; j++) {
            data_[j] = data_[j + 1];
        }
        size_--;
    }

    void swap(Vector& other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(data_, other.data_);
    }

    void clear() {
        size_ = 0;
    }

    void emplace(int i, const T& val) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        for (int j = size_; j > i; j--) {
            data_[j] = data_[j - 1];
        }
        data_[i] = val;
        size_++;
    }

    void emplace_back(const T& val) {
        if (size_ == capacity_) {
            reserve(2 * capacity_);
        }
        data_[size_] = val;
        size_++;
    }

    // Operators
    bool operator==(const Vector& rhs) const {
        if (size_ != rhs.size_) {
            return false;
        }
        for (int i = 0; i < size_; i++) {
            if (data_[i] != rhs.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Vector& rhs) const {
        for (int i = 0; i < size_; i++) {
            if (data_[i] < rhs.data_[i]) {
                return true;
            }
            else if (data_[i] > rhs.data_[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator<=(const Vector& rhs) const {
        return (*this < rhs || *this == rhs);
    }

    bool operator>(const Vector& rhs) const {
        return !(*this <= rhs);
    }

    bool operator>=(const Vector& rhs) const {
        return !(*this < rhs);
    }
};
#endif 