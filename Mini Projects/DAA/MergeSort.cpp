// Merge Sort Algorithm

#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function that merges the two halves of a array
void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];

    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;

    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// Function that divides the arrays in two halves and merges them
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Function to Print Array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << ", ";
    cout << "\n";
}

int main()
{
    // Large Array (size=10,000) given as input
    int arr[10000];
    for (int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;

    // Find the Size of Array
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    // Print the Given Array
    cout << "Given Array: \n";
    printArray(arr, arr_size);
    cout << "\n";

    // Start the timer/clock
    auto start = high_resolution_clock::now();
    // Apply Merge Sort to the Array
    mergeSort(arr, 0, arr_size - 1);
    // Stop the timer/clock
    auto stop = high_resolution_clock::now();

    // Print the Sorted Array
    cout << "\nSorted Array using Normal Merge Sort: \n";
    printArray(arr, arr_size);

    // Find the time taken to Sort (stop - start)
    auto duration = duration_cast<microseconds>(stop - start);

    // Display the time taken to Sort
    cout << "\nTime taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}