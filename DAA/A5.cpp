//                                    Assignment No.: A1
// Name: Akash Kalme                                                Roll No.: 41141
// Write a program for analysis of quick sort by using deterministic and randomized variant.

#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartion(vector<int> &arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}
void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = randomizedPartion(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr;
    int choice;
    do
    {
        cout << "\nMain Menu\n";
        cout << "1. Deterministic Quick Sort\n";
        cout << "2. Randomized Quick Sort\n";
        cout << "-1. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int n;
            cout << "Enter the Number of Elements in the Array: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cout << "Enter the " << (i + 1) << "th Element: ";
                cin >> x;
                arr.push_back(x);
            }
            randomizedQuickSort(arr, 0, n - 1);
            cout << "Sorted Array using Deteministic Quick Sort: ";
            printArray(arr);
            arr.clear();
            break;

        case 2:
            cout << "Enter the Number of Elements in the Array: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int x;
                cout << "Enter the " << (i + 1) << "th Element: ";
                cin >> x;
                arr.push_back(x);
            }
            deterministicQuickSort(arr, 0, n - 1);
            cout << "Sorted Array using Randomized Quick Sort: ";
            printArray(arr);
            arr.clear();
            break;

        case -1:
            cout << "Thank You!\n";
            exit;
            break;

        default:
            cout << "Invalid Choice!";
            break;
        }
    } while (choice != -1);
    return 0;
}