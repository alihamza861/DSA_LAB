#include <iostream>
#include <string>
using namespace std;

// Priority levels for reservation
enum Priority { CASUAL = 1, ASSIGNMENT = 2, RESEARCH = 3 };

string priorityToString(Priority p) {
    switch (p) {
        case RESEARCH:   return "Research";
        case ASSIGNMENT: return "Assignment";
        case CASUAL:     return "Casual";
        default:         return "Unknown";
    }
}

// Node representing a student reservation
class StudentNode {
public:
    string name;
    Priority priority;
    StudentNode* next;

    StudentNode(string studentName, Priority prio)
        : name(studentName), priority(prio), next(nullptr) {}
};

// Reservation queue for a single book
class ReservationQueue {
private:
    StudentNode* head;
    string bookTitle;
    int count;

public:
    ReservationQueue(string title) : head(nullptr), bookTitle(title), count(0) {}

    string getTitle() const { return bookTitle; }

    // Add a new student — inserts in priority order (higher priority = closer to front)
    void addStudent(string name, Priority priority) {
        StudentNode* newStudent = new StudentNode(name, priority);

        // Insert at beginning if queue is empty or new student has higher priority than head
        if (head == nullptr || priority > head->priority) {
            newStudent->next = head;
            head = newStudent;
        } else {
            StudentNode* temp = head;
            while (temp->next != nullptr && temp->next->priority >= priority)
                temp = temp->next;
            newStudent->next = temp->next;
            temp->next = newStudent;
        }
        count++;
        cout << "[" << bookTitle << "] " << name
             << " added (Priority: " << priorityToString(priority) << ").\n";
    }

    // Remove a student by name (cancellation)
    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "No reservations for \"" << bookTitle << "\".\n";
            return;
        }
        if (head->name == name) {
            StudentNode* toDelete = head;
            head = head->next;
            delete toDelete;
            count--;
            cout << name << " removed from reservation list of \"" << bookTitle << "\".\n";
            return;
        }
        StudentNode* temp = head;
        while (temp->next != nullptr && temp->next->name != name)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << name << " not found in reservation list of \"" << bookTitle << "\".\n";
        } else {
            StudentNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            count--;
            cout << name << " removed from reservation list of \"" << bookTitle << "\".\n";
        }
    }

    // Update a student's priority and re-sort
    void updatePriority(string name, Priority newPriority) {
        // Remove existing entry
        if (head == nullptr) {
            cout << "No reservations for \"" << bookTitle << "\".\n";
            return;
        }
        bool found = false;
        if (head->name == name) {
            StudentNode* toDelete = head;
            head = head->next;
            delete toDelete;
            count--;
            found = true;
        } else {
            StudentNode* temp = head;
            while (temp->next != nullptr && temp->next->name != name)
                temp = temp->next;
            if (temp->next != nullptr) {
                StudentNode* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                count--;
                found = true;
            }
        }

        if (!found) {
            cout << name << " not found in reservation list of \"" << bookTitle << "\".\n";
            return;
        }

        cout << name << "'s priority updated to " << priorityToString(newPriority) << ".\n";
        addStudent(name, newPriority);
    }

    // Display the reservation list for this book
    void display() {
        cout << "\n=== Reservation List for \"" << bookTitle << "\" ===\n";
        if (head == nullptr) {
            cout << "  No reservations.\n";
            return;
        }
        StudentNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            cout << "  " << pos++ << ". " << temp->name
                 << " [" << priorityToString(temp->priority) << "]\n";
            temp = temp->next;
        }
        cout << "Total: " << count << " student(s)\n";
    }

    // Count reservations
    void countStudents() {
        cout << "\"" << bookTitle << "\" has " << count << " student(s) in reservation list.\n";
    }

    // Book returned — serve the student at the front of the queue
    void bookReturned() {
        if (head == nullptr) {
            cout << "No one waiting for \"" << bookTitle << "\".\n";
            return;
        }
        StudentNode* served = head;
        head = head->next;
        count--;
        cout << "Book \"" << bookTitle << "\" returned. "
             << served->name << " (" << priorityToString(served->priority)
             << ") is now served and removed from queue.\n";
        delete served;
    }

    ~ReservationQueue() {
        StudentNode* temp = head;
        while (temp) {
            StudentNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
    }
};

int main() {
    cout << "======================================\n";
    cout << "  University Library Reservation System\n";
    cout << "======================================\n\n";

    // Two book queues
    ReservationQueue book1("Data Structures by Cormen");
    ReservationQueue book2("Operating Systems by Tanenbaum");

    // --- Book 1 Operations ---
    cout << "--- Operations for Book 1 ---\n";
    book1.addStudent("Ali Hassan", CASUAL);
    book1.addStudent("Sara Ahmed", RESEARCH);
    book1.addStudent("Usman Tariq", ASSIGNMENT);
    book1.addStudent("Maryam Noor", RESEARCH);
    book1.addStudent("Bilal Khan", CASUAL);
    book1.display();

    cout << "\n-- Usman cancels reservation --\n";
    book1.removeStudent("Usman Tariq");
    book1.display();

    cout << "\n-- Ali upgrades to Assignment priority --\n";
    book1.updatePriority("Ali Hassan", ASSIGNMENT);
    book1.display();

    cout << "\n-- Book returned, serving front student --\n";
    book1.bookReturned();
    book1.display();
    book1.countStudents();

    // --- Book 2 Operations ---
    cout << "\n--- Operations for Book 2 ---\n";
    book2.addStudent("Zara Ali", ASSIGNMENT);
    book2.addStudent("Hamza Sheikh", RESEARCH);
    book2.addStudent("Fatima Malik", CASUAL);
    book2.addStudent("Omar Farooq", RESEARCH);
    book2.display();

    cout << "\n-- Fatima cancels reservation --\n";
    book2.removeStudent("Fatima Malik");
    book2.display();

    cout << "\n-- Book returned twice --\n";
    book2.bookReturned();
    book2.bookReturned();
    book2.display();
    book2.countStudents();

    return 0;
}
