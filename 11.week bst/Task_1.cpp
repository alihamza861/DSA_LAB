#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)       root->left  = insert(root->left,  val);
    else if (val > root->data)  root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->data) return true;
    if (key < root->data)  return search(root->left,  key);
    return                        search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter number of values to insert: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal:   "; inorder(root);   cout << endl;
    cout << "Preorder Traversal:  "; preorder(root);  cout << endl;
    cout << "Postorder Traversal: "; postorder(root); cout << endl;

    int key;
    cout << "\nEnter key to search: ";
    cin >> key;
    cout << (search(root, key) ? "Key found in BST" : "Key not found in BST") << endl;

    return 0;
}
