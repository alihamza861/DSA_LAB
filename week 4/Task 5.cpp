#include <iostream>
using namespace std;

class PrintQueue {
    string* arr;
    int front, rear, size, capacity;

public:
    PrintQueue(int cap) {
        capacity = cap;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(string doc) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = doc;
        size++;
        cout << "Added: " << doc << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No documents to print!\n";
            return;
        }
        cout << "Printing: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Next document: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending documents.\n";
            return;
        }
        cout << "Print Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    PrintQueue q(5);

    q.enqueue("Doc1");
    q.enqueue("Doc2");
    q.enqueue("Doc3");

    q.display();
    q.peek();

    q.dequeue();
    q.display();

    return 0;
}