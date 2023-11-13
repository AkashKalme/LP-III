//                                    Assignment No.: A1
// Name: Akash Kalme                                                Roll No.: 41141
// Design n-Queens matrix having first Queen placed. Use backtracking to place remaining Queens to
// generate the final n-Queen's matrix.

#include <iostream>
#include <vector>

using namespace std;

int X = 1;

void printSolution(vector<vector<char>> &board, int n)
{
    cout << "Arrangement " << X << "\n";
    X++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if two queens threaten each other or not
bool isSafe(vector<vector<char>> &board, int r, int c, int n)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 'Q')
        {
            return 0;
        }
    }

    // return 0 if two queens share the same `` diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }

    // return 0 if two queens share the same `/` diagonal
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return 0;
        }
    }
    return 1;
}

void nQueen(vector<vector<char>> &board, int r, int n)
{
    // if `N` queens are placed successfully, print the solution
    if (r == n)
    {
        printSolution(board, n);
        return;
    }
    // place queen at every square in the current row `r`
    // and recur for each valid movement
    for (int i = 0; i < n; i++)
    {
        // if no two queens threaten each other
        if (isSafe(board, r, i, n))
        {
            // place queen on the current square
            board[r][i] = 'Q';
            // recur for the next row
            nQueen(board, r + 1, n);
            // backtrack and remove the queen from the current square
            board[r][i] = 'X';
        }
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, 'X'));
    nQueen(board, 0, n);
    return 0;
}