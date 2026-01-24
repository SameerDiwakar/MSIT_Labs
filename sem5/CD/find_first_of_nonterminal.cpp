#include <iostream>
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
