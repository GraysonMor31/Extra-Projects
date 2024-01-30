#include "binaryTree.h"
#include <iostream>
#include <string>

using namespace std;

string print_tree(Node<int>* node, string prefix, bool isLeft) {
    if (node == nullptr) {
        return "";
    }
    string result = "";
    if (isLeft) {
        result += prefix + "|-- ";
    } else {
        result += prefix + "\\-- ";
    }
    result += to_string(node->data) + "\n";
    result += print_tree(node->left, prefix + (isLeft ? "|   " : "    "), true);
    result += print_tree(node->right, prefix + (isLeft ? "|   " : "    "), false);
    return result;
}

// Preorder traversal
void preorder(Node<int>* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal
void inorder(Node<int>* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder traversal
void postorder(Node<int>* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    BinaryTree<int> tree;
    tree.insert(nullptr, 5);
    tree.insert(nullptr, 3);
    tree.insert(nullptr, 7);
    tree.insert(nullptr, 2);
    tree.insert(nullptr, 4);
    tree.insert(nullptr, 6);
    tree.insert(nullptr, 8);

    cout << print_tree(tree.getRoot(), "", false) << endl;

    tree.remove(nullptr, 5);
    tree.remove(nullptr, 3);

    cout << print_tree(tree.getRoot(), "", false) << endl;

    tree.height(tree.getRoot());
    cout << "Height: " << tree.height(tree.getRoot()) << endl;

    cout << "Preorder traversal: ";
    preorder(tree.getRoot());
    cout << endl;
    cout << "Inorder traversal: ";
    inorder(tree.getRoot());
    cout << endl;
    cout << "Postorder traversal: ";
    postorder(tree.getRoot());
    cout << endl;
    return 0;
}

