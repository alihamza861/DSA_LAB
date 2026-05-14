
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void print(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";
        print(temp->next);
    }

    void display()
    {
        print(head);
    }

    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        display();
    }

    Node* insertEndRec(Node* temp, int val)
    {
        if (temp == NULL)
            return new Node(val);

        temp->next = insertEndRec(temp->next, val);
        return temp;
    }

    void insertAtEnd(int val)
    {
        head = insertEndRec(head, val);
        display();
    }

    Node* insertPosRec(Node* temp, int val, int pos)
    {
        if (pos == 1)
        {
            Node* newNode = new Node(val);
            newNode->next = temp;
            return newNode;
        }

        if (temp == NULL)
            return NULL;

        temp->next = insertPosRec(temp->next, val, pos - 1);
        return temp;
    }

    void insertAtPosition(int val, int pos)
    {
        head = insertPosRec(head, val, pos);
        display();
    }

    Node* deleteByValueRec(Node* temp, int val)
    {
        if (temp == NULL)
            return NULL;

        if (temp->data == val)
        {
            Node* del = temp->next;
            delete temp;
            return del;
        }

        temp->next = deleteByValueRec(temp->next, val);
        return temp;
    }

    void deleteByValue(int val)
    {
        head = deleteByValueRec(head, val);
        display();
    }

    Node* deleteByPosRec(Node* temp, int pos)
    {
        if (temp == NULL)
            return NULL;

        if (pos == 1)
        {
            Node* del = temp->next;
            delete temp;
            return del;
        }

        temp->next = deleteByPosRec(temp->next, pos - 1);
        return temp;
    }

    void deleteByPosition(int pos)
    {
        head = deleteByPosRec(head, pos);
        display();
    }

    int searchRec(Node* temp, int val, int pos)
    {
        if (temp == NULL)
            return -1;

        if (temp->data == val)
            return pos;

        return searchRec(temp->next, val, pos + 1);
    }

    void search(int val)
    {
        int result = searchRec(head, val, 1);

        if (result == -1)
            cout << "Value not found\n";
        else
            cout << "Found at position: " << result << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);

    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.insertAtPosition(15, 3);

    list.deleteByValue(20);

    list.deleteByPosition(2);

    list.search(15);

    return 0;
}