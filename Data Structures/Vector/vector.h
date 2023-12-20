#ifndef VECTOR_H_INCLUDED;
#define VECTOR_H_INCLUDED;
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

    // Constructors
    Vector() : size_(0), capacity_(1), data_(new T[capacity_]) {}
    Vector(int n) : size_(n), capacity_(n), data_(new T[capacity_]) {}
    // Copy constructor
    Vector(const Vector& v) : size_(v.size_), capacity_(v.capacity_), data_(new T[capacity_]) {
        std::copy(v.data_, v.data_ + size_, data_);
    }
    // Move constructor
    Vector(Vector&& v) : size_(v.size_), capacity_(v.capacity_), data_(v.data_) {
        v.data_ = nullptr;
    }
    // Destructor
    ~Vector() {
        delete[] data_;
    }

    // Accessors 
    int size() const { 
        return size_; 
    }

    int capacity() const { 
        return capacity_; 
    }

    bool empty() const {
        return size_ == 0;
    }

    T& front() const {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        } 
        return data_[0]; 
    }

    T& front() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        } 
        return data_[0]; 
    }

    T& back() const {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        } 
        return data_[size_ - 1]; 
    }

    T& back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        } 
        return data_[size_ - 1]; 
    }

    T& at(int i) const {
        if (i < 0 || i >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[i];
    }

    T& operator[](int i) const {
        return data_[i];
    }

    // Mutators
    void resize(int n) {
        if (n > capacity_) {
            capacity_ = n;
            T* new_data = new T[capacity_];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
        }
        size_ = n;
    }

    void reserve(int n) {
        if (n > capacity_) {
            capacity_ = n;
            T* new_data = new T[capacity_];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
        }
    }

    void push_back (const T& value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            T* new_data = new T[capacity_];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
        }
        data_[size_] = value;
        size_++;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        size_--;
    }

    void shrink_to_fit() {
        capacity_ = size_;
        T* new_data = new T[capacity_];
        std::copy(data_, data_ + size_, new_data);
        delete[] data_;
        data_ = new_data;
    }

    void clear() {
        size_ = 0;
    }

    void swap(Vector& v) {
        std::swap(size_, v.size_);
        std::swap(capacity_, v.capacity_);
        std::swap(data_, v.data_);
    }

    // Operators
    Vector& operator=(const Vector& v) {
        if (this != &v) {
            size_ = v.size_;
            capacity_ = v.capacity_;
            delete[] data_;
            data_ = new T[capacity_];
            std::copy(v.data_, v.data_ + size_, data_);
        }
        return *this;
    }

    Vector& operator=(Vector&& v) {
        if (this != &v) {
            size_ = v.size_;
            capacity_ = v.capacity_;
            delete[] data_;
            data_ = v.data_;
            v.data_ = nullptr;
        }
        return *this;
    }

    Vector& operator+=(const Vector& v) {
        if (size_ + v.size_ > capacity_) {
            capacity_ = size_ + v.size_;
            T* new_data = new T[capacity_];
            std::copy(data_, data_ + size_, new_data);
            delete[] data_;
            data_ = new_data;
        }
        std::copy(v.data_, v.data_ + v.size_, data_ + size_);
        size_ += v.size_;
        return *this;
    }

    Vector& operator+=(const T& value) {
    push_back(value);
    return *this;
    }

    Vector operator+(const Vector& v) const {
        Vector result(*this);
        result operator+= v;
        return result;
    }

    Vector operator+(const T& value) const {
        Vector result(*this);
        result += value;
        return result;
    }

    Vector& operator-=(const Vector& v) {
        if (n > size_) {
            throw std::out_of_range("Index out of range");
        }
        size_ -= n;
        return *this;
    }

    Vector& operator-=(const T& value) {
        pop_back();
        return *this;
    }

    Vector operator-(const Vector& v) const {
        Vector result(*this);
        result -= n;
        return result;
    }

    Vector operator-(const T& value) const {
        Vector result(*this);
        result -= value;
        return result;
    }

    // Comparison operators
    bool operator==(const Vector& v) const {
        if (size_ != v.size_) {
            return false;
        }
        for (int i = 0; i < size_; i++) {
            if (data_[i] != v.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& v) const {
        return !(*this == v);
    }

    bool operator<(const Vector& v) const {
        int min_size = std::min(size_, v.size_);
        for (int i = 0; i < min_size; i++) {
            if (data_[i] < v.data_[i]) {
                return true;
            }
            else if (data_[i] > v.data_[i]) {
                return false;
            }
        }
        return size_ < v.size_;
    }

    bool operator<=(const Vector& v) const {
        return *this < v || *this == v;
    }

    bool operator>(const Vector& v) const {
        return !(*this <= v);
    }

    bool operator>=(const Vector& v) const {
        return !(*this < v);
    }

    // Iterators
    T* begin() const {
        return data_;
    }

    T* begin () {
        return data_;
    }

    T* end() const {
        return data_ + size_;
    }

    T* end() {
        return data_ + size_;
    }
};
#endif 