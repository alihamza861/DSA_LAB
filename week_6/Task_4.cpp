#include <iostream>
#include <string>
using namespace std;

// Node representing a patient
class PatientNode {
public:
    string name;
    int id;
    PatientNode* next;

    PatientNode(int patientId, string patientName)
        : id(patientId), name(patientName), next(nullptr) {}
};

class PatientQueue {
private:
    PatientNode* head;
    int size;

public:
    PatientQueue() : head(nullptr), size(0) {}

    // Add a new patient to the end of the queue
    void addPatient(int id, string name) {
        PatientNode* newPatient = new PatientNode(id, name);
        if (head == nullptr) {
            head = newPatient;
        } else {
            PatientNode* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newPatient;
        }
        size++;
        cout << "Patient [" << id << "] " << name << " added to queue.\n";
    }

    // Remove a patient by name (cancellation)
    void removePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        if (head->name == name) {
            PatientNode* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            cout << "Patient " << name << " removed from queue (appointment cancelled).\n";
            return;
        }
        PatientNode* temp = head;
        while (temp->next != nullptr && temp->next->name != name)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Patient " << name << " not found in queue.\n";
        } else {
            PatientNode* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            size--;
            cout << "Patient " << name << " removed from queue (appointment cancelled).\n";
        }
    }

    // Display the current patient queue
    void displayQueue() {
        if (head == nullptr) {
            cout << "Queue is empty. No patients waiting.\n";
            return;
        }
        cout << "\n--- Current Patient Queue ---\n";
        PatientNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            cout << pos++ << ". [ID: " << temp->id << "] " << temp->name << "\n";
            temp = temp->next;
        }
        cout << "-----------------------------\n";
    }

    // Count how many patients are in the queue
    void countPatients() {
        cout << "Total patients in queue: " << size << "\n";
    }

    ~PatientQueue() {
        PatientNode* temp = head;
        while (temp) {
            PatientNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
    }
};

int main() {
    PatientQueue queue;

    cout << "=== Hospital Patient Queue System ===\n\n";

    // Adding patients
    queue.addPatient(101, "Alice Khan");
    queue.addPatient(102, "Bob Smith");
    queue.addPatient(103, "Carol White");
    queue.addPatient(104, "David Brown");
    queue.addPatient(105, "Eve Johnson");

    queue.displayQueue();
    queue.countPatients();

    cout << "\n-- Bob cancels appointment --\n";
    queue.removePatient("Bob Smith");
    queue.displayQueue();

    cout << "\n-- David cancels appointment --\n";
    queue.removePatient("David Brown");
    queue.displayQueue();
    queue.countPatients();

    cout << "\n-- Try to remove someone not in queue --\n";
    queue.removePatient("Zara Ali");

    return 0;
}
