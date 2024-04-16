#include <iostream>
#include <algorithm>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    //declaring the array
    int myArray[1000];

    //populate the array
    for (int i = 0; i < 999; ++i)
    {
        myArray[i] = rand() % 1000; //random values between 0 - 1000
    }
    int arraySize = 50;             //size we want to sort
    quickSort(myArray, 0, arraySize - 1);

    //print sorted array
    std::cout << "Sorted array:\n";
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << myArray[i] << "\n";
    }
    return true;
}