#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printLeafNodes(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    Node* root  = new Node(40);
    Node* n20   = new Node(20);
    Node* n60   = new Node(60);
    Node* n10   = new Node(10);
    Node* n30   = new Node(30);
    Node* n50   = new Node(50);
    Node* n70   = new Node(70);

    root->left  = n20;
    root->right = n60;
    n20->left   = n10;
    n20->right  = n30;
    n60->left   = n50;
    n60->right  = n70;

    cout << "Root Node: " << root->data << endl;
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;
    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    return 0;
}
