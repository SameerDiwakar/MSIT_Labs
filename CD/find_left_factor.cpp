 #include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Production {
    string nonTerminal;
    vector<string> rhs;
};

// Function to find longest common prefix among RHS
string longestCommonPrefix(const vector<string>& prods) {
    if (prods.empty()) return "";
    string prefix = prods[0];
    for (int i = 1; i < prods.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < prods[i].size() && prefix[j] == prods[i][j])
            j++;
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

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

        cout << "Enter productions (without spaces, separate by | ): ";
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

    cout << "\n--- Left Factored Grammar ---\n";
    for (auto &prod : grammar) {
        string A = prod.nonTerminal;
        string prefix = longestCommonPrefix(prod.rhs);

        if (prefix.size() > 0 && prefix.size() < prod.rhs[0].size()) {
            string Aprime = A + "'";
            cout << A << " -> " << prefix << Aprime << endl;
            cout << Aprime << " -> ";
            for (int i = 0; i < prod.rhs.size(); i++) {
                string suffix = prod.rhs[i].substr(prefix.size());
                if (suffix == "") suffix = "ε";
                cout << suffix;
                if (i != prod.rhs.size() - 1) cout << " | ";
            }
            cout << endl;
        } else {
            cout << A << " -> ";
            for (int i = 0; i < prod.rhs.size(); i++) {
                cout << prod.rhs[i];
                if (i != prod.rhs.size() - 1) cout << " | ";
            }
            cout << endl;
        }
    }

    return 0;
}
