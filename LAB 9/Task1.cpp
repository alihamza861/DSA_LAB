#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};

class Doubly {

private:
	Node* head;

public:

	Doubly() {
		head = NULL;
	}


	void insertatend(int val) {

		Node* newnode = new Node(val);

		if (head == NULL) {
			head = newnode;
			return;
		}

		Node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newnode;
		newnode->prev = temp;
	}


	void insertatstart(int val) {

		Node* newnode = new Node(val);

		if (head == NULL) {
			head = newnode;
			return;
		}

		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}


	void insertatposition(int pos, int val) {

		if (pos <= 0) {
			cout << "Invalid Position!" << endl;
			return;
		}

		if (pos == 1) {
			insertatstart(val);
			return;
		}

		Node* temp = head;

		for (int i = 1; i < pos - 1 && temp != NULL; i++) {
			temp = temp->next;
		}

		if (temp == NULL) {
			cout << "Invalid Position!" << endl;
			return;
		}

		Node* newnode = new Node(val);

		newnode->next = temp->next;
		newnode->prev = temp;

		if (temp->next != NULL) {
			temp->next->prev = newnode;
		}

		temp->next = newnode;
	}


	void deletebyvalue(int val) {

		if (head == NULL) {
			cout << "List is Empty!" << endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL && temp->data != val) {
			temp = temp->next;
		}

		if (temp == NULL) {
			cout << "Value not found!" << endl;
			return;
		}


		if (temp == head) {

			head = head->next;

			if (head != NULL) {
				head->prev = NULL;
			}

			delete temp;
			return;
		}


		if (temp->next != NULL) {
			temp->next->prev = temp->prev;
		}

		if (temp->prev != NULL) {
			temp->prev->next = temp->next;
		}

		delete temp;
	}


	void displayforward() {

		if (head == NULL) {
			cout << "List is Empty!" << endl;
			return;
		}

		Node* temp = head;

		cout << "Forward Traversal: ";

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}


	void displayreverse() {

		if (head == NULL) {
			cout << "List is Empty!" << endl;
			return;
		}

		Node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		cout << "Reverse Traversal: ";

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->prev;
		}

		cout << endl;
	}


	~Doubly() {

		Node* temp;

		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {

	Doubly dll;


	dll.insertatend(10);
	dll.insertatend(20);
	dll.insertatend(30);

	cout << "After inserting at end:" << endl;
	dll.displayforward();


	dll.insertatstart(5);

	cout << "\nAfter inserting at start:" << endl;
	dll.displayforward();


	dll.insertatposition(3, 15);

	cout << "\nAfter inserting at position 3:" << endl;
	dll.displayforward();


	cout << endl;
	dll.displayreverse();


	dll.deletebyvalue(5);

	cout << "\nAfter deleting 5:" << endl;
	dll.displayforward();


	dll.deletebyvalue(30);

	cout << "\nAfter deleting 30:" << endl;
	dll.displayforward();


	cout << endl;
	dll.displayreverse();

	return 0;
}