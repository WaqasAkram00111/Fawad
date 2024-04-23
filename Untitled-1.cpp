#include <iostream>
using namespace std;

// Define a Binary Search Tree (BST) node
struct BSTNode {
    int value;
    BSTNode *left, *right;

    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Class for Binary Search Tree (BST)
class BST {
private:
    BSTNode *root;

    // Helper function for in-order traversal
    void inOrderHelper(BSTNode *node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        cout << node->value << " ";
        inOrderHelper(node->right);
    }

    // Helper function for insertion
    BSTNode *insertHelper(BSTNode *node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }

        if (value < node->value) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    // Helper function for search
    BSTNode *searchHelper(BSTNode *node, int value) {
        if (node == nullptr || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

public:
    BST() : root(nullptr) {}

    // Insertion function
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // In-order traversal function
    void inOrder() {
        inOrderHelper(root);
        cout << endl;
    }

    // Search function
    bool search(int value) {
        return searchHelper(root, value) != nullptr;
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    cout << "In-order traversal of BST: ";
    tree.inOrder();

    cout << "Searching for 7 in BST: " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Searching for 12 in BST: " << (tree.search(12) ? "Found" : "Not Found") << endl;

    return 0;
}
