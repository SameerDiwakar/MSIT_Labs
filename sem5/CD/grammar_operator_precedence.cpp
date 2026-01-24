#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool OperatorPrecedenceGrammar(const vector<string>& productions) {
    for (const string& prod : productions) {
        size_t pos = prod.find("->");
        if (pos == string::npos) {
            cout << "Invalid production format: " << prod << endl;
            return false;
        }

        string lhs = prod.substr(0, pos);
        string rhs = prod.substr(pos + 2);

        if (rhs.find("epsilon") != string::npos) {
            cout << "Epsilon production found in: " << prod << endl;
            return false;
        }

        for (size_t i = 0; i < rhs.length() - 1; ++i) {
            if (isupper(rhs[i]) && isupper(rhs[i + 1])) {
                cout << "Adjacent non-terminals found in: " << prod << endl;
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();

    vector<string> productions(n);
    cout << "Enter productions (in the format A->B): " << endl;
    for (int i = 0; i < n; ++i) {
        getline(cin, productions[i]);
    }

    cout << "Checking if the grammar is an operator precedence grammar..." << endl;
    if (OperatorPrecedenceGrammar(productions)) {
        cout << "The grammar is an operator precedence grammar." << endl;
    } else {
        cout << "The grammar is not an operator precedence grammar." << endl;
    }

    return 0;
}

/*
Enter number of productions: 3
Enter productions (in the format A->B): 
E->E+T
E->T
T->id
Checking if the grammar is an operator precedence grammar...
The grammar is an operator precedence grammar.

*/
