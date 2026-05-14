#include <iostream>
using namespace std;

int arraysum(int arr[], int size)
{
    
    if (size == 0)
        return 0;

   
    return arr[size - 1] + arraysum(arr, size - 1);
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = arraysum(arr, size);
    cout << "Sum of array elements = " << sum << endl;

    return 0;
}