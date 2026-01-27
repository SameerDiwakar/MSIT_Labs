Sameer: #include <iostream>
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