#include <iostream>
using namespace std;

struct Package {
    int id;
    string address;
    int startTime;
    int endTime;
};

class DeliveryQueue {
    Package* arr;
    int front, rear, size, capacity;

public:
    DeliveryQueue(int cap) {
        capacity = cap;
        arr = new Package[capacity];
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

    void enqueue(Package p) {
        if (isFull()) {
            cout << "Queue full!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = p;
        size++;
        cout << "Package added: " << p.id << endl;
    }

    void dequeue(int currentTime) {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        Package p = arr[front];

        if (currentTime > p.endTime) {
            cout << "Package " << p.id << " expired!\n";
        } else {
            cout << "Delivered package " << p.id << endl;
        }

        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        Package p = arr[front];
        cout << "Next Package:\n";
        cout << "ID: " << p.id << ", Address: " << p.address
             << ", Time: " << p.startTime << "-" << p.endTime << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packages in queue.\n";
            return;
        }

        cout << "Packages in Queue:\n";
        for (int i = 0; i < size; i++) {
            Package p = arr[(front + i) % capacity];
            cout << "ID: " << p.id << ", Address: " << p.address
                 << ", Time: " << p.startTime << "-" << p.endTime << endl;
        }
    }
};

int main() {
    DeliveryQueue dq(5);

    dq.enqueue({101, "Lahore", 10, 15});
    dq.enqueue({102, "Karachi", 12, 18});
    dq.enqueue({103, "Islamabad", 9, 11});

    dq.display();

    int currentTime = 16;

    dq.dequeue(currentTime);
    dq.dequeue(currentTime);

    dq.display();

    return 0;
}