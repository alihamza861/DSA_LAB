#include<iostream>
using namespace std;

class myqueue{
private:
    int* arr;
    int f, r, size;

public:
    myqueue(int s){
        size = s;
        arr = new int[size];
        f = -1;
        r = -1;
    }
    void enqueue(int id){
        if(r == size - 1){
            cout << "Queue full\n";
        }
        else{
            if(f == -1) f = 0;
            r++;
            arr[r] = id;
            cout << "Ticket " << id << " added\n";
        }
    }

    void dequeue(){
        if(f == -1 || f > r){
            cout << "No tickets\n";
        }
        else{
            cout << "Ticket " << arr[f] << " resolved\n";
            f++;
        }
    }

    void front(){
        if(f == -1 || f > r){
            cout << "No tickets\n";
        }
        else{
            cout << "Next ticket: " << arr[f] << endl;
        }
    }

    void display(){
        if(f == -1 || f > r){
            cout << "No tickets\n";
        }
        else{
            cout << "Tickets: ";
            for(int i = f; i <= r; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int size, choice, id;

    cout << "Enter size: ";
    cin >> size;

    myqueue q(size);

    do{
        cout << "\n1. Add Ticket\n2. Resolve Ticket\n3. Next Ticket\n4. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter ticket id: ";
            cin >> id;
            q.enqueue(id);
        }
        else if(choice == 2){
            q.dequeue();
        }
        else if(choice == 3){
            q.front();
        }
        else if(choice == 4){
            q.display();
        }

    }while(choice != 0);

    return 0;
}