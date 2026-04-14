#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert at beginning — O(1)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning.\n";
    }

    // Insert at end — O(n)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at end.\n";
    }

    // Delete a node by value — O(n)
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        // If head itself holds the value
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << value << " deleted.\n";
            return;
        }
        // Search for the node
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << value << " not found in list.\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            cout << value << " deleted.\n";
        }
    }

    // Traverse and display the list — O(n)
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.deleteByValue(20);
    list.display();

    list.deleteByValue(99);  // not found case
    list.display();

    return 0;
}
