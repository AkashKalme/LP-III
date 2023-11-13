//                                    Assignment No.: A1
// Name: Akash Kalme                                                Roll No.: 41141
// Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their
// time and space complexity.

#include <iostream>

using namespace std;

void iterativeFibonacciSeries(int n)
{
    int f1 = 0;
    int f2 = 1;
    int f3 = 0;
    if (n == 1)
    {
        cout << f1 << "\n";
        return;
    }
    cout << f1 << " " << f2 << " ";
    for (int i = 2; i < n; i++)
    {
        f3 = f1 + f2;
        cout << f3 << " ";
        f1 = f2;
        f2 = f3;
    }
    cout << "\n";
}

int recursiveFibonacciSeriesHelper(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return recursiveFibonacciSeriesHelper(n - 1) + recursiveFibonacciSeriesHelper(n - 2);
}

int main()
{
    int choice;
    do
    {
        cout << "\nMain Menu\n";
        cout << "1. Iterative (Non-Recursive) Approach\n";
        cout << "2. Recursive Approach\n";
        cout << "-1. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        int n;

        switch (choice)
        {
        case 1:
            cout << "Enter Number of Fibonacci Numbers to be Calculated: ";
            cin >> n;
            cout << "Fibonacci Series using Iterative Approach: ";
            iterativeFibonacciSeries(n);
            break;

        case 2:
            cout << "Enter Number of Fibonacci Numbers to be Calculated: ";
            cin >> n;
            cout << "Fibonacci Series using Recursive Approach: ";
            for (int i = 0; i < n; i++)
            {
                cout << recursiveFibonacciSeriesHelper(i) << " ";
            }
            cout << "\n";
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