#include<iostream>
#include<string>
using namespace std;

class Node {
public:

	int songid;
	string songname;
	float duration;

	Node* next;
	Node* prev;

	Node(int id, string name, float dur) {

		songid = id;
		songname = name;
		duration = dur;

		next = NULL;
		prev = NULL;
	}
};

class Playlist {

private:

	Node* head;
	Node* current;

public:

	Playlist() {
		head = NULL;
		current = NULL;
	}


	void addsong(int id, string name, float dur) {

		Node* newnode = new Node(id, name, dur);


		if (head == NULL) {
			head = newnode;
			current = head;
			return;
		}

		Node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newnode;
		newnode->prev = temp;
	}


	void displayplaylist() {

		if (head == NULL) {
			cout << "Playlist is Empty!" << endl;
			return;
		}

		Node* temp = head;

		cout << "\nPlaylist Songs:\n" << endl;

		while (temp != NULL) {

			cout << "Song ID: " << temp->songid << endl;
			cout << "Song Name: " << temp->songname << endl;
			cout << "Duration: " << temp->duration << " mins" << endl;

			cout << endl;

			temp = temp->next;
		}
	}


	void deletesong(string name) {

		if (head == NULL) {
			cout << "Playlist is Empty!" << endl;
			return;
		}

		Node* temp = head;

		while (temp != NULL && temp->songname != name) {
			temp = temp->next;
		}


		if (temp == NULL) {
			cout << "Song not found!" << endl;
			return;
		}


		if (temp == head) {

			head = head->next;

			if (head != NULL) {
				head->prev = NULL;
			}

			if (current == temp) {
				current = head;
			}

			delete temp;

			cout << "Song deleted successfully!" << endl;
			return;
		}


		if (temp->next != NULL) {
			temp->next->prev = temp->prev;
		}

		if (temp->prev != NULL) {
			temp->prev->next = temp->next;
		}

		if (current == temp) {
			current = temp->next;
		}

		delete temp;

		cout << "Song deleted successfully!" << endl;
	}


	void playcurrent() {

		if (current == NULL) {
			cout << "No song available!" << endl;
			return;
		}

		cout << "\nCurrently Playing:" << endl;
		cout << "Song Name: " << current->songname << endl;
	}


	void playnext() {

		if (current == NULL) {
			cout << "No song available!" << endl;
			return;
		}

		if (current->next == NULL) {
			cout << "This is the last song!" << endl;
			return;
		}

		current = current->next;

		cout << "\nNext Song:" << endl;
		cout << "Song Name: " << current->songname << endl;
	}


	void playprevious() {

		if (current == NULL) {
			cout << "No song available!" << endl;
			return;
		}

		if (current->prev == NULL) {
			cout << "This is the first song!" << endl;
			return;
		}

		current = current->prev;

		cout << "\nPrevious Song:" << endl;
		cout << "Song Name: " << current->songname << endl;
	}

	void reverseplaylist() {

		if (head == NULL) {
			cout << "Playlist is Empty!" << endl;
			return;
		}

		Node* currentnode = head;
		Node* temp = NULL;

		while (currentnode != NULL) {

			temp = currentnode->prev;
			currentnode->prev = currentnode->next;
			currentnode->next = temp;

			currentnode = currentnode->prev;
		}

		if (temp != NULL) {
			head = temp->prev;
		}

		current = head;

		cout << "\nPlaylist Reversed Successfully!" << endl;
	}


	~Playlist() {

		Node* temp;

		while (head != NULL) {

			temp = head;
			head = head->next;

			delete temp;
		}
	}
};

int main() {

	Playlist p;


	p.addsong(1, "Shape of You", 4.2);
	p.addsong(2, "Believer", 3.8);
	p.addsong(3, "Perfect", 4.5);
	p.addsong(4, "Faded", 3.6);


	p.displayplaylist();


	p.playcurrent();


	p.playnext();


	p.playnext();


	p.playprevious();


	cout << endl;
	p.deletesong("Perfect");


	p.displayplaylist();


	p.reverseplaylist();


	p.displayplaylist();

	return 0;
}