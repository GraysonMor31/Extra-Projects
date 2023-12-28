#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED

template <typename T, typename U>
class HashMap {
private:
    int size;
    T *keys;
    U *values;
public:
    HashMap() : size(0), keys(nullptr), values(nullptr) {}
    HashMap(int size) : size(size), keys(new T[size]), values(new U[size]) {}
    HashMap(const HashMap &other) : size(other.size), keys(new T[other.size]), values(new U[other.size]) {
        copy(other.keys, other.keys + other.size, keys);
    }

    ~HashMap() {
        delete[] keys;
        delete[] values;
    }

    HashMap &operator=(const HashMap &other) {
        if (this != &other) {
            delete[] keys;
            delete[] values;
            size = other.size;
            keys = new T[other.size];
            values = new U[other.size];
            copy(other.keys, other.keys + other.size, keys);
        }
        return *this;
    }

    

};
#endif