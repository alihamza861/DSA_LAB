#include<iostream>
using namespace std;

template <typename T>
class myqueue{
private:
    T* arr;
    int f, r, size;

public:
    myqueue(int s){
        size = s;
        arr = new T[size];
        f = 0;
        r = -1;
    }

    void enqueue(T val){
        if(r == size - 1){
            cout << "full\n";
        }
        else{
            r++;
            arr[r] = val;
        }
    }

    void display(){
        if(r < f){
            cout << "empty\n";
        }
        else{
            for(int i = f; i <= r; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    
    void reverseK(int k){
        int n = r - f + 1;

        if(k <= 1 || k > n){
            return;
        }

        int start = f;
        int end = f + k - 1;

        while(start < end){
            T temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }
};

int main(){
    int n, x, k;

    cout << "size: ";
    cin >> n;

    myqueue<int> q(n);

    cout << "enter values:\n";
    for(int i = 0; i < n; i++){
        cin >> x;
        q.enqueue(x);
    }

    q.display();

    cout << "k: ";
    cin >> k;

    q.reverseK(k);

    q.display();

    return 0;
}