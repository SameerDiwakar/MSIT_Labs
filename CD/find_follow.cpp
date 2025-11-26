#include <bits/stdc++.h>
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
