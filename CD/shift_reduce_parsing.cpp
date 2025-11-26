#include <bits/stdc++.h>
using namespace std;

struct Production {
    char lhs;
    string rhs;
};

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    vector<Production> grammar(n);
    cout << "Enter productions (example: E->E+T):\n";
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        grammar[i].lhs = prod[0];
        grammar[i].rhs = prod.substr(3);
    }

    string input;
    cout << "Enter input string (end with $): ";
    cin >> input;

    string stack = "";
    int ptr = 0;

    cout << "\nStack\tInput\tAction\n";
    while (true) {
        cout << stack << "\t" << input.substr(ptr) << "\t";

        bool reduced = false;
        for (auto &prod : grammar) {
            int len = prod.rhs.size();
            if (stack.size() >= len && stack.substr(stack.size() - len) == prod.rhs) {
                stack.erase(stack.size() - len);
                stack.push_back(prod.lhs);
                cout << "Reduce by " << prod.lhs << "->" << prod.rhs << "\n";
                reduced = true;
                break;
            }
        }
        if (reduced) continue;

        if (ptr < input.size()) {
            stack.push_back(input[ptr++]);
            cout << "Shift\n";
        } else if (stack == string(1, grammar[0].lhs) && ptr == input.size()) {
            cout << "Accept\n";
            break;
        } else {
            cout << "Error\n";
            break;
        }
    }
    return 0;
}
