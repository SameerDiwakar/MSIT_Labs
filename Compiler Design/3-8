[03-09-2025 22:41] Sameer: #include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

map<string, vector<vector<string>>> grammar;
string startSymbol;
vector<string> tokens;

bool isNonTerminal(const string &symbol) {
    return grammar.find(symbol) != grammar.end();
}

pair<bool, int> parse(const string &nonTerminal, int pos) {
    if (pos > (int)tokens.size()) return {false, pos};

    for (auto &production : grammar[nonTerminal]) {
        int curPos = pos;
        bool matched = true;

        for (auto &symbol : production) {
            if (symbol == "ε") continue;  // epsilon case

            else if (isNonTerminal(symbol)) {
                auto res = parse(symbol, curPos);
                if (!res.first) {
                    matched = false;
                    break;
                }
                curPos = res.second;
            } 
            else {
                if (curPos < (int)tokens.size() && tokens[curPos] == symbol) {
                    curPos++;
                } else {
                    matched = false;
                    break;
                }
            }
        }

        if (matched) return {true, curPos};
    }
    return {false, pos};
}

vector<string> tokenize(const string &input) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (ss >> temp) result.push_back(temp);
    return result;
}

int main() {
    int n;
    cout << "Enter number of non-terminals: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nonTerminal;
        cout << "Enter non-terminal " << (i + 1) << ": ";
        getline(cin, nonTerminal);

        if (i == 0) startSymbol = nonTerminal;

        int p;
        cout << "Enter number of productions for <" << nonTerminal << ">: ";
        cin >> p;
        cin.ignore();

        for (int j = 0; j < p; j++) {
            string prodLine;
            cout << "Enter production " << (j + 1) 
                 << " (tokens separated by space, use ε for epsilon): ";
            getline(cin, prodLine);

            vector<string> production = tokenize(prodLine);
            grammar[nonTerminal].push_back(production);
        }
    }

    cout << "\nStart symbol is: " << startSymbol << "\n";
    cout << "Enter input string tokens separated by space: ";
    string inputLine;
    getline(cin, inputLine);

    tokens = tokenize(inputLine);

    auto res = parse(startSymbol, 0);

    if (res.first && res.second == (int)tokens.size())
        cout << "✅ String is accepted by the grammar.\n";
    else
        cout << "❌ String is NOT accepted by the grammar.\n";

    return 0;
}
[03-09-2025 22:41] Sameer: #3
[03-09-2025 22:50] Sameer: #include <iostream>
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
[03-09-2025 22:52] Sameer: #4
[03-09-2025 22:58] Sameer: #include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;

map<string, vector<vector<string>>> grammar;
map<string, set<string>> first;

bool isTerminal(const string &symbol) {
    return grammar.find(symbol) == grammar.end();
}

void computeFirst() {
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &nt : grammar) {
            string nonTerminal = nt.first;
            for (auto &production : nt.second) {
                bool epsilonInAll = true;
                for (auto &symbol : production) {
                    if (isTerminal(symbol)) {
                        if (first[nonTerminal].insert(symbol).second)
                            changed = true;
                        epsilonInAll = false;
                        break;
                    } else {
                        for (auto &s : first[symbol]) {
                            if (s != "ε") {
                                if (first[nonTerminal].insert(s).second)
                                    changed = true;
                            }
                        }
                        if (first[symbol].find("ε") == first[symbol].end()) {
                            epsilonInAll = false;
                            break;
                        }
                    }
                }
                if (epsilonInAll) {
                    if (first[nonTerminal].insert("ε").second)
                        changed = true;
                }
            }
        }
    }
}

void printFirstSets() {
    for (auto &nt : first) {
        cout << "FIRST(" << nt.first << ") = { ";
        for (auto it = nt.second.begin(); it != nt.second.end(); it++) {
            cout << *it;
            auto nxt = it;
            nxt++;
            if (nxt != nt.second.end()) cout << ", ";
        }
        cout << " }" << endl;
    }
}

int main() {
    // Example Grammar from notes:
    grammar["E"] = { {"T", "E'"} };
    grammar["E'"] = { {"+", "T", "E'"}, {"ε"} };
    grammar["T"] = { {"F", "T'"} };
    grammar["T'"] = { {"*", "F", "T'"}, {"ε"} };
    grammar["F"] = { {"(", "E", ")"}, {"id"} };

    computeFirst();
    printFirstSets();

    return 0;
}
[03-09-2025 22:58] Sameer: #5
[03-09-2025 23:02] Sameer: #include <iostream>
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
[03-09-2025 23:02] Sameer: #6

[17-09-2025 14:52] Sameer: #include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> g;
map<char, set<char>> firstSet, followSet;
char start;

// FIRST function
set<char> FIRST(char X) {
    if (!isupper(X)) return {X};
    if (!firstSet[X].empty()) return firstSet[X];
    for (string rhs : g[X]) {
        bool eps = true;
        for (char c : rhs) {
            set<char> f = FIRST(c);
            eps = f.count('#');
            f.erase('#');
            firstSet[X].insert(f.begin(), f.end());
            if (!eps) break;
        }
        if (eps) firstSet[X].insert('#');
    }
    return firstSet[X];
}

// FOLLOW function
void FOLLOW(char X) {
    for (auto &p : g) {
        char A = p.first;
        for (string rhs : p.second) {
            for (int i = 0; i < rhs.size(); i++) {
                if (rhs[i] == X) {
                    if (i + 1 < rhs.size()) {
                        set<char> f = FIRST(rhs[i + 1]);
                        if (f.count('#')) {
                            FOLLOW(A);
                            followSet[X].insert(followSet[A].begin(), followSet[A].end());
                        }
                        f.erase('#');
                        followSet[X].insert(f.begin(), f.end());
                    } else if (A != X) {
                        FOLLOW(A);
                        followSet[X].insert(followSet[A].begin(), followSet[A].end());
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string prod;
        cin >> prod;              // e.g. E->E+T
        g[prod[0]].push_back(prod.substr(3));
        if (i == 0) start = prod[0];
    }

    for (auto &p : g) FIRST(p.first);
    followSet[start].insert('$');
    for (auto &p : g) FOLLOW(p.first);

    for (auto &p : g) {
        cout << "FOLLOW(" << p.first << ") = { ";
        for (char c : followSet[p.first]) cout << c << " ";
        cout << "}\n";
    }
}
[17-09-2025 14:52] Sameer: #7 follow of given grammar
[17-09-2025 14:55] Sameer: #include <bits/stdc++.h>
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
[17-09-2025 14:55] Sameer: #8 shift reduce parsing from a string
