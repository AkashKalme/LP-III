//                                    Assignment No.: A3
// Name: Akash Kalme                                                Roll No.: 41141
// Write a program to solve a 0 - 1 Knapsack problem using dynamic programming or branch and bound strategy.

// Dynamic Programming using Tabulation (Bottom-Up) Approach
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;

            if (wt[ind] <= cap)
            {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }

            dp[ind][cap] = max(notTaken, taken);
        }
    }
    return dp[n - 1][W];
}

int main()
{
    vector<int> wt;
    vector<int> val;
    int n;
    cout << "Enter the Number of Items in House: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w;
        int v;
        cout << "Enter the Weight of " << (i + 1) << "th Item: ";
        cin >> w;
        cout << "Enter the Value of " << (i + 1) << "th Item: ";
        cin >> v;
        wt.push_back(w);
        val.push_back(v);
    }
    int W;
    cout << "Enter the Capacity of Knapsack: ";
    cin >> W;

    cout << "\nMaximum Value of Items the Thief can Steal: " << knapsack(wt, val, n, W);
    return 0;
}

// 2 3 4 5
// 3 4 5 6
// 5