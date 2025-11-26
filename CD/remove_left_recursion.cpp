#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Production {
    string nonTerminal;
    vector<string> rhs;
};

int main() {
    int n;
    cout << "Enter number of non-terminals: ";
    cin >> n;
    cin.ignore();

    vector<Production> grammar(n);

    // Input grammar
    for (int i = 0; i < n; i++) {
        cout << "Enter non-terminal " << i + 1 << ": ";
        cin >> grammar[i].nonTerminal;
        int p;
        cout << "Enter number of productions for " << grammar[i].nonTerminal << ": ";
        cin >> p;
        cin.ignore();
        cout << "Enter productions separated by space (use '|' for alternatives):\n";
        string line;
        getline(cin, line);

        string temp = "";
        for (char c : line) {
            if (c == '|') {
                grammar[i].rhs.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) grammar[i].rhs.push_back(temp);
    }

    cout << "\n--- Removing Left Recursion ---\n";
    for (auto &prod : grammar) {
        string A = prod.nonTerminal;
        vector<string> alpha, beta;

        // Split into alpha (starts with A) and beta (does not)
        for (auto &rule : prod.rhs) {
            if (rule[0] == A[0]) {
                alpha.push_back(rule.substr(1));  // remove leading A
            } else {
                beta.push_back(rule);
            }
        }

        if (!alpha.empty()) {
            // Left recursion exists
            string Aprime = A + "'";
            cout << A << " -> ";
            for (int i = 0; i < (int)beta.size(); i++) {
                cout << beta[i] << Aprime;
                if (i != (int)beta.size() - 1) cout << " | ";
            }
            cout << endl;

            cout << Aprime << " -> ";
            for (int i = 0; i < (int)alpha.size(); i++) {
                cout << alpha[i] << Aprime << " | ";
            }
            cout << "ε" << endl;
        } else {
            // No left recursion
            cout << A << " -> ";
            for (int i = 0; i < (int)prod.rhs.size(); i++) {
                cout << prod.rhs[i];
                if (i != (int)prod.rhs.size() - 1) cout << " | ";
            }
            cout << endl;
        }
    }

    return 0;
}

