#include <iostream>
#include "myStack.h"
using namespace std;

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    myStack<int> s(size);

    int choice, value;

    do {
        cout << "\nStack menu \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Show Top\n";
        cout << "4. Check if empty\n";
        cout << "5. Check if full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
    if (s.isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }
    break;

        case 5:
    if (s.isFull()) {
        cout << "Stack is full\n";
    } else {
        cout << "Stack is not full\n";
    }
    break;
        case 6:
            s.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}