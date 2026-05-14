

#include <iostream>
using namespace std;


int findLargest(int arr[], int size, int index = 0, int maxIndex = 0)
{
    if (index == size)
        return maxIndex;

    if (arr[index] > arr[maxIndex])
        maxIndex = index;

    return findLargest(arr, size, index + 1, maxIndex);
}


bool subsetSum(int arr[], int size, int target, int index)
{
   
    if (target == 0)
        return true;

    if (index == size || target < 0)
        return false;

   
    return subsetSum(arr, size, target - arr[index], index + 1)
        || subsetSum(arr, size, target, index + 1);
}


int magicNumber(int arr[], int size)
{
    if (size == 0)
        return -1;

    int maxIndex = findLargest(arr, size);
    int largest = arr[maxIndex];

    
    int* newArr = new int[size - 1];

    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != maxIndex)
        {
            newArr[j] = arr[i];
            j++;
        }
    }

    if (subsetSum(newArr, size - 1, largest, 0))
        return largest;

    return magicNumber(newArr, size - 1);
}

int main()
{
    int arr[] = { 2, 3, 5, 8, 13 };
    int size = 5;

    cout << "Magic Number: " << magicNumber(arr, size);

    return 0;
}