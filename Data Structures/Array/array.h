#ifndef ARRAY_H_INLCUDED
#define ARRAY_H_INLCUDED

#include <algorithm>
#include <cmath>

template <typename T>

class Array {
private:
    T* data_;
    int size_;
public:

    /* Member Functions*/
    Array(int size_) : size_(size_), data_(new T[size_]) {}

    Array(const Array& other) : size_(other.size_), data_(new T[other.size_]) {
        std::copy(other.data_, other.data_ + size_, data_);
    }

    ~Array() { 
        delete[] data_; 
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = new T[size_];
            std::copy(other.data_, other.data_ + size_, data_);
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

    int max_size() {
        return std::pow(2, 32) / sizeof(T);
    }

    bool empty() const {
        return size_ == 0;
    }

    // Element Access
    T& operator[](int index) {
        return data_[index];
    }

    T& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    T& front() const{
        return data_[0];
    }

    T& back() const{
        return data_[size_ - 1];
    }

    // Modifiers
    void fill(const T& value) {
        std::fill(data_, data_ + size_, value);
    }

    void swap(Array& other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    // Operators
    bool operator==(const Array& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (int i = 0; i < size_; i++) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Array& other) const {
        return !(*this == other);
    }

    bool operator<(const Array& other) const {
        for (int i = 0; i < size_; i++) {
            if (data_[i] < other.data_[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator<=(const Array& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Array& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Array& other) const {
        return !(*this < other);
    }
};
#endif