#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void BFS(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
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

    cout << "BFS / Level-Order Traversal: ";
    BFS(root);
    cout << endl;

    return 0;
}
