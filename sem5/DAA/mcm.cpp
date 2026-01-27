#include <bits/stdc++.h>
using namespace std;

void printOptimal(vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "M" << i;
        return;
    }
    cout << "(";
    printOptimal(s, i, s[i][j]);
    cout << " x ";
    printOptimal(s, s[i][j] + 1, j);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    vector<pair<int, int>> dims(n + 1);
    cout << "\nEnter dimensions (rows and columns of each matrix):\n";
    for (int i = 1; i <= n; i++) {
        int r, c;
        cout << "Matrix " << i << ": ";
        cin >> r >> c;
        dims[i] = {r, c};
        p[i - 1] = r;
        p[i] = c;
    }

    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum number of multiplications = " << m[1][n] << endl;
    cout << "Optimal Parenthesization: ";
    printOptimal(s, 1, n);
    cout << endl;

    return 0;
}

/*
Enter number of matrices: 3

Enter dimensions (rows and columns of each matrix):
Matrix 1: 5 10
Matrix 2: 10 15
Matrix 3: 15 5

Minimum number of multiplications = 1000
Optimal Parenthesization: (M1 x (M2 x M3))

*/
