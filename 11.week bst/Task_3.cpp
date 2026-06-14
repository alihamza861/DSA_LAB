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
    if (val < root->data)      root->left  = insert(root->left,  val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isIdentical(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->data == root2->data)
        && isIdentical(root1->left,  root2->left)
        && isIdentical(root1->right, root2->right);
}

int main() {
    Node* tree1 = nullptr;
    for (int v : {50, 30, 70, 20, 40}) tree1 = insert(tree1, v);

    Node* tree2 = nullptr;
    for (int v : {50, 30, 70, 20, 40}) tree2 = insert(tree2, v);

    Node* tree3 = nullptr;
    for (int v : {50, 30, 70, 25, 40}) tree3 = insert(tree3, v);

    cout << "Tree 1 Inorder: "; inorder(tree1); cout << endl;
    cout << "Tree 2 Inorder: "; inorder(tree2); cout << endl;
    cout << "Tree 3 Inorder: "; inorder(tree3); cout << endl;

    cout << "\nTree 1 and Tree 2: "
         << (isIdentical(tree1, tree2) ? "Identical" : "Not Identical") << endl;
    cout << "Tree 1 and Tree 3: "
         << (isIdentical(tree1, tree3) ? "Identical" : "Not Identical") << endl;

    return 0;
}
