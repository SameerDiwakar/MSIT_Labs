#include <iostream>
#include <vector>
using namespace std;

void computeLPS(string pat, vector<int> &lps) {
    int m = pat.size();
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    vector<int> lps(m);
    computeLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "ABCABCDABABCABCD";
    string pattern = "ABCD";
    KMPSearch(text, pattern);
    return 0;
}

// Pattern found at index 3
// Pattern found at index 12
