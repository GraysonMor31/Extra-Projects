#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <algorithm>
#include <cmath>

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    // Return the root of the tree
    Node<T>* getRoot() {
        return this->root;
    }

    // Insert a node into the tree
    void insert(Node<T>* node, T data) {
        if (node == nullptr) {
            this->root = new Node<T>(data);
            return;
        }
        if (data < node->data) {
            if (node->left == nullptr) {
                node->left = new Node<T>(data);
            } else {
                insert(node->left, data);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node<T>(data);
            } else {
                insert(node->right, data);
            }
        }
    }

    void remove(Node<T>* node, T data) {
        if (node == nullptr) {
            return;
        }
        if (data < node->data) {
            remove(node->left, data);
        } else if (data > node->data) {
            remove(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node<T>* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node<T>* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node<T>* temp = findMin(node->right);
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
    }

    void find(Node<T>* node, T data) {
        if (node == nullptr) {
            return;
        }
        if (data < node->data) {
            find(node->left, data);
        } else if (data > node->data) {
            find(node->right, data);
        } else {
            return;
        }
    }

    void find_min(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr) {
            return node;
        }
        return find_min(node->left);
    }

    void find_max(Node<T>* node) {
        if (node == nullptr) {
            return;
        }
        if (node->right == nullptr) {
            return node;
        }
        return find_max(node->right);
    }

    int height(Node<T>* node) {
        if (node == nullptr) {
            return -1;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }

    int size(Node<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + size(node->left) + size(node->right);
    }
    

};
#endif