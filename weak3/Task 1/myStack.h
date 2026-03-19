#include <iostream>
#include "AbstractStack.h"
using namespace std;

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int topIndex;
    int capacity;

public:
    
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    
    ~myStack() {
        delete[] arr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return T();
        }
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack (Top → Bottom):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};
