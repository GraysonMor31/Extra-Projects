#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <algorithm>

template <typename T>
class List {
private: 
    struct Node {
        T data;
        Node *next;
        Node *prev;
        Node(const T& d = T(), Node *n = nullptr, Node *p = nullptr) : data(d), next(n), prev(p) {}
    };
    Node *head;
    Node *tail;
    int size_;

public:
    List() : head(nullptr), tail(nullptr), size_(0) {}
    List(const List& rhs) : head(nullptr), tail(nullptr), size_(0) { *this = rhs; }
    ~List() { 
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    List& operator=(const List& rhs) {
        if (this != &rhs) {
            clear();
            for (Node *ptr = rhs.head; ptr != nullptr; ptr = ptr->next) {
                push_back(ptr->data);
            }
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        Node *ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->data;
    }

    Node *begin() const { 
        return head; 
    }

    Node *end() const { 
        return nullptr; 
    }

    void push_back(const T& data) {
        if (head == nullptr) {
            head = new Node(data);
            tail = head;
        } else {
            tail->next = new Node(data, nullptr, tail);
            tail = tail->next;
        }
        ++size_;
    }

    void push_front(const T& data) {
        if (head == nullptr) {
            head = new Node(data);
            tail = head;
        } else {
            head->prev = new Node(data, head, nullptr);
            head = head->prev;
        }
        ++size_;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        } else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        --size_;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        } else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        --size_;
    }

    void insert(const T& data, int index) {
        if (index < 0 || index > size_) {
            return;
        } else if (index == 0) {
            push_front(data);
        } else if (index == size_) {
            push_back(data);
        } else {
            Node *ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            Node *temp = new Node(data, ptr, ptr->prev);
            ptr->prev->next = temp;
            ptr->prev = temp;
            ++size_;
        }
    }

    void erase(int index) {
        if (index < 0 || index >= size_) {
            return;
        } else if (index == 0) {
            pop_front();
        } else if (index == size_ - 1) {
            pop_back();
        } else {
            Node *ptr = head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
            --size_;
        }
    }

    int find(const T& data) const {
        int index = 0;
        for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
            if (ptr->data == data) {
                return index;
            }
            ++index;
        }
        return -1;
    }

    void clear() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size_ = 0;
    }

    int size() const { 
        return size_; 
    }

    bool empty() const { 
        return size_ == 0; 
    }
};
#endif