#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int i, string t) : isbn(i), title(t), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int isbn;
    string title;
    ListNode* next;
    ListNode(int i, string t) : isbn(i), title(t), next(nullptr) {}
};

BSTNode* insert(BSTNode* root, int isbn, string title) {
    if (!root) return new BSTNode(isbn, title);
    if (isbn < root->isbn)      root->left  = insert(root->left,  isbn, title);
    else if (isbn > root->isbn) root->right = insert(root->right, isbn, title);
    return root;
}

void convertToList(BSTNode* root, ListNode*& head, ListNode*& tail) {
    if (!root) return;
    convertToList(root->left, head, tail);
    ListNode* node = new ListNode(root->isbn, root->title);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    convertToList(root->right, head, tail);
}

void printList(ListNode* head) {
    cout << "Sorted Library Catalog (Linked List):" << endl;
    int i = 1;
    while (head) {
        cout << i++ << ". ISBN: " << head->isbn << " | Title: " << head->title << endl;
        head = head->next;
    }
}

int main() {
    BSTNode* root = nullptr;
    root = insert(root, 1045, "Data Structures and Algorithms");
    root = insert(root, 1020, "Introduction to Programming");
    root = insert(root, 1060, "Operating Systems");
    root = insert(root, 1010, "Discrete Mathematics");
    root = insert(root, 1030, "Computer Networks");
    root = insert(root, 1055, "Database Systems");
    root = insert(root, 1075, "Artificial Intelligence");

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    convertToList(root, head, tail);

    printList(head);

    return 0;
}
