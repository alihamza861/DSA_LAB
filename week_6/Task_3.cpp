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

    // Insert at a specific position (1-based)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position.\n";
            return;
        }
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << value << " inserted at position " << position << ".\n";
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range. Inserting at end.\n";
            // find actual end
            if (head == nullptr) { head = newNode; }
            else {
                Node* t = head;
                while (t->next) t = t->next;
                t->next = newNode;
            }
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted at position " << position << ".\n";
        }
    }

    // Delete at a specific position (1-based)
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (position < 1) {
            cout << "Invalid position.\n";
            return;
        }
        if (position == 1) {
            Node* toDelete = head;
            head = head->next;
            cout << toDelete->data << " deleted from position 1.\n";
            delete toDelete;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != nullptr; i++)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Position out of range.\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            cout << toDelete->data << " deleted from position " << position << ".\n";
            delete toDelete;
        }
    }

    // Search for an element (returns 1-based position, -1 if not found)
    void search(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << value << " not found in the list.\n";
    }

    // Count total number of nodes
    void countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total nodes: " << count << "\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) { cout << "List is empty.\n"; return; }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
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

void showMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Insert node at a specific position\n";
    cout << "2. Delete node at a specific position\n";
    cout << "3. Search for an element\n";
    cout << "4. Count total number of nodes\n";
    cout << "5. Display list\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    SinglyLinkedList list;
    int choice, value, position;

    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                list.display();
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                list.display();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 4:
                list.countNodes();
                break;
            case 5:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
