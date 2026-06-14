#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    // Insert
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    // Find minimum node (used in deletion)
    Node* minNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // Delete
    Node* deleteNode(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Case 1: Leaf node
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children — replace with in-order successor
            Node* successor = minNode(node->right);
            node->data = successor->data;
            node->right = deleteNode(node->right, successor->data);
        }
        return node;
    }

    // In-order traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void insert(int val)        { root = insert(root, val); }
    void deleteVal(int val)     { root = deleteNode(root, val); }
    void printInorder()         { inorder(root); cout << endl; }
};

int main() {
    BST tree;

    // Insert: 50, 30, 70, 20, 40, 60, 80
    for (int val : {50, 30, 70, 20, 40, 60, 80})
        tree.insert(val);

    cout << "After Insertion: ";
    tree.printInorder();   // Expected: 20 30 40 50 60 70 80

    // Delete: 70
    tree.deleteVal(70);
    cout << "After Deletion:  ";
    tree.printInorder();   // Expected: 20 30 40 50 60 80

    return 0;
}
