#include <iostream>
#include <string>
using namespace std;

template <typename T>
void printarray(T array[], int s) {
    for (int i = 0; i < s; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void selectionsort(T arr[], int s) {
    for (int i = 0; i < s; i++) {
        int minindex = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}


int main() {
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intSize = 5;
    printarray(intArray, intSize);
    selectionsort(intArray, intSize);

    printarray(intArray, intSize);
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    int  stringsize = 4;
    printarray(stringArray, stringsize);
    selectionsort(stringArray, stringsize);

    printarray(stringArray, stringsize);
    return 0;
}
