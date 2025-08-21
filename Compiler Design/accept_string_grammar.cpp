//prog to check given string accepted by given grammar

//length of string is n
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Grammar representation:
// Key: Non-terminal symbol (string)
// Value: Vector of productions, each production is a vector of strings (either 1 or 2 elements)
using Grammar = unordered_map<string, vector<vector<string>>>;

bool cyk_algorithm(const Grammar& grammar, const string& start_symbol, const string& s) {
    int n = s.size();
    if (n == 0) {
        // CYK doesn't typically handle epsilon productions
        return false;
    }

    // 3D table: table[length][start] = set of variables that generate substring s[start:start+length]
    vector<vector<unordered_set<string>>> table(n, vector<unordered_set<string>>(n));

    // Fill table for substrings of length 1 (terminals)
    for (int j = 0; j < n; j++) {
        string terminal(1, s[j]);
        for (const auto& [var, productions] : grammar) {
            for (const auto& prod : productions) {
                if (prod.size() == 1 && prod[0] == terminal) {
                    table[0][j].insert(var);
                }
            }
        }
    }

    // Fill table for substrings length > 1
    for (int length = 2; length <= n; length++) {
        for (int start = 0; start <= n - length; start++) {
            for (int partition = 1; partition < length; partition++) {
                const unordered_set<string>& left_cell = table[partition - 1][start];
                const unordered_set<string>& right_cell = table[length - partition - 1][start + partition];

                for (const auto& [var, productions] : grammar) {
                    for (const auto& prod : productions) {
                        if (prod.size() == 2) {
                            if (left_cell.count(prod[0]) > 0 && right_cell.count(prod[1]) > 0) {
                                table[length - 1][start].insert(var);
                            }
                        }
                    }
                }
            }
        }
    }

    // Check if start symbol generates entire string
    return table[n - 1][0].count(start_symbol) > 0;
}

int main() {
    // Example grammar in CNF for a^n b^n (simple)
    Grammar grammar = {
        {"S", {{"A", "B"}}},
        {"A", {{"a"}}},
        {"B", {{"b"}}}
    };

    string input_string = "ab";

    bool accepted = cyk_algorithm(grammar, "S", input_string);

    cout << "The string '" << input_string << "' is "
         << (accepted ? "accepted" : "rejected") << " by the grammar." << endl;

    return 0;
}
