#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> solutions;
vector<string> board;
vector<int> leftRow, upperDiag, lowerDiag;

void solve(int col) {
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 && 
            lowerDiag[row + col] == 0 && 
            upperDiag[n - 1 + col - row] == 0) {

            board[row][col] = 'Q';
            leftRow[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 1;

            solve(col + 1);

            board[row][col] = '.';
            leftRow[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 0;
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    board = vector<string>(n, string(n, '.'));
    leftRow = vector<int>(n, 0);
    upperDiag = vector<int>(2 * n - 1, 0);
    lowerDiag = vector<int>(2 * n - 1, 0);

    solve(0);

    cout << "\nTotal Solutions: " << solutions.size() << endl;

    for (auto &sol : solutions) {
        cout << "\nSolution:\n";
        for (auto &row : sol)
            cout << row << endl;
    }

    return 0;
}