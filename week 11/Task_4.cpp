#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void DFS(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right) s.push(curr->right);
        if (curr->left)  s.push(curr->left);
    }
}

int main() {
    Node* root  = new Node(40);
    Node* n20   = new Node(20);
    Node* n60   = new Node(60);
    Node* n10   = new Node(10);
    Node* n30   = new Node(30);
    Node* n50   = new Node(50);
    Node* n70   = new Node(70);

    root->left  = n20;  root->right = n60;
    n20->left   = n10;  n20->right  = n30;
    n60->left   = n50;  n60->right  = n70;

    cout << "DFS Traversal: ";
    DFS(root);
    cout << endl;

    return 0;
}
