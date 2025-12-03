#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &board, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = board[r];
        if (c == col || abs(c - col) == abs(r - row))
            return false;
    }
    return true;
}

void solveNQ(int row, int n, vector<int> &board, vector<vector<int>> &solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQ(row + 1, n, board, solutions);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens [N]: ";
    cin >> n;

    vector<int> board(n, -1);
    vector<vector<int>> solutions;
    solveNQ(0, n, board, solutions);

    for (auto &sol : solutions) {
        cout << "[";
        for (int x : sol) cout << x;
        cout << "]\n";
    }

    return 0;
}

/*
Enter number of queens [N]: 4
[1302]
[2031]

*/
