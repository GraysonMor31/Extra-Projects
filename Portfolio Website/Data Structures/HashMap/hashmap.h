#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED

template <typename K, typename V>
class HashMap {
private:
    struct Entry {
        K key_;
        V value_;
        Entry *next_;
    };

    Entry **table_;
    int size_;
    int capacity_;

    int hash(K key) {
        return key % capacity_;
    }

    bool equals(K key1, K key2) {
        return key1 == key2;
    }

    void resize() {
        int newCapacity = capacity_ * 2;
        Entry **newTable = new Entry*[newCapacity];
        for (int i = 0; i < newCapacity; i++) {
            newTable[i] = NULL;
        }
        for (int i = 0; i < capacity_; i++) {
            Entry *entry = table_[i];
            while (entry != NULL) {
                int index = hash(entry->key_);
                Entry *next = entry->next_;
                entry->next_ = newTable[index];
                newTable[index] = entry;
                entry = next;
            }
        }
        delete[] table_;
        table_ = newTable;
        capacity_ = newCapacity;
    }

public:

    HashMap() : size_(0), capacity_(10) {
        table_ = new Entry*[capacity_];
        for (int i = 0; i < capacity_; i++) {
            table_[i] = NULL;
        }
    }

    ~HashMap() {
        for (int i = 0; i < capacity_; i++) {
            Entry *entry = table_[i];
            while (entry != NULL) {
                Entry *prev = entry;
                entry = entry->next_;
                delete prev;
            }
        }
        delete[] table_;
    }

    void put(K key, V value) {
        int index = hash(key);
        Entry *entry = table_[index];
        Entry *prev = NULL;
        while (entry != NULL) {
            if (entry->key_ == key) {
                entry->value_ = value;
                return;
            }
            prev = entry;
            entry = entry->next_;
        }
        entry = new Entry();
        entry->key_ = key;
        entry->value_ = value;
        entry->next_ = table_[index];
        table_[index] = entry;
        ++size_;
        if (size_ >= capacity_) {
            resize();
        }
    }

    V get(K key) {
        int index = hash(key);
        Entry *entry = table_[index];
        while (entry != NULL) {
            if (entry->key_ == key) {
                return entry->value_;
            }
            entry = entry->next_;
        }
        throw std::runtime_error("Key not found");
    }

    void remove(K key) {
        int index = hash(key);
        Entry *entry = table_[index];
        Entry *prev = NULL;
        while (entry != NULL) {
            if (entry->key_ == key) {
                if (prev == NULL) {
                    table_[index] = entry->next_;
                } else {
                    prev->next_ = entry->next_;
                }
                delete entry;
                size_--;
                return;
            }
            prev = entry;
            entry = entry->next_;
        }
    }

    int size() {
        return size_;
    }

    bool isEmpty() {
        return size_ == 0;
    }
};
#endif