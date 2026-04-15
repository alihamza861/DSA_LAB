#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int rollNumber;
    StudentNode* next;

    StudentNode(string n, int roll) {
        name = n;
        rollNumber = roll;
        next = nullptr;
    }
};

class StudentList {
private:
    StudentNode* head;
    int count;

public:
    StudentList() {
        head = nullptr;
        count = 0;
    }

    void addStudent(string name, int roll) {
        StudentNode* newStudent = new StudentNode(name, roll);

        if (head == nullptr) {
            head = newStudent;
        } else {
            StudentNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        count++;
        cout << "Student Added: " << name << " (Roll: " << roll << ")\n";
    }

    void addAtBeginning(string name, int roll) {
        StudentNode* newStudent = new StudentNode(name, roll);
        newStudent->next = head;
        head = newStudent;
        count++;
        cout << "Student Added at Beginning: " << name << " (Roll: " << roll << ")\n";
    }

    void deleteStudent(int roll) {
        if (head == nullptr) {
            cout << "List is empty! No student to delete.\n";
            return;
        }

        if (head->rollNumber == roll) {
            StudentNode* toDelete = head;
            head = head->next;
            delete toDelete;
            count--;
            cout << "Student with Roll " << roll << " deleted.\n";
            return;
        }

        StudentNode* temp = head;
        while (temp->next != nullptr && temp->next->rollNumber != roll) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student with Roll " << roll << " not found!\n";
        } else {
            StudentNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            count--;
            cout << "Student with Roll " << roll << " deleted.\n";
        }
    }

    void searchStudent(int roll) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        StudentNode* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->rollNumber == roll) {
                cout << "Student Found! Name: " << temp->name 
                     << ", Roll: " << temp->rollNumber 
                     << ", Position: " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Student with Roll " << roll << " not found!\n";
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "\n=== STUDENT LIST ===\n";
            cout << "No students in the list.\n";
            return;
        }

        StudentNode* temp = head;
        int serial = 1;
        while (temp != nullptr) {
            cout << serial++ << ". " << temp->name 
                 << " (Roll: " << temp->rollNumber << ")\n";
            temp = temp->next;
        }
        cout << "Total Students: " << count << "\n";
    }

    void totalStudents() {
        cout << "Total students in list: " << count << "\n";
    }

    ~StudentList() {
        StudentNode* temp = head;
        while (temp != nullptr) {
            StudentNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    StudentList list;
    int choice, roll;
    string name;

    do {
        cout << "1. Add Student at End\n";
        cout << "2. Add Student at Beginning\n";
        cout << "3. Delete Student by Roll Number\n";
        cout << "4. Search Student by Roll Number\n";
        cout << "5. Display All Students\n";
        cout << "6. Show Total Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Roll Number: ";
                cin >> roll;
                list.addStudent(name, roll);
                break;

            case 2:
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Roll Number: ";
                cin >> roll;
                list.addAtBeginning(name, roll);
                break;

            case 3:
                cout << "Enter Roll Number to Delete: ";
                cin >> roll;
                list.deleteStudent(roll);
                break;

            case 4:
                cout << "Enter Roll Number to Search: ";
                cin >> roll;
                list.searchStudent(roll);
                break;

            case 5:
                list.displayAll();
                break;

            case 6:
                list.totalStudents();
                break;

            case 7:
                cout << "Exiting Program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 7);

    return 0;
}
