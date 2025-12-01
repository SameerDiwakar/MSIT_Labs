#include <bits/stdc++.h>
using namespace std;

string lcsRec(string &s1, string &s2, int m, int n) {
    if (m == 0 || n == 0)
        return "";
    if (s1[m - 1] == s2[n - 1]) {
        return lcsRec(s1, s2, m - 1, n - 1) + s1[m - 1];
    }
    string a = lcsRec(s1, s2, m, n - 1);
    string b = lcsRec(s1, s2, m - 1, n);
    return (a.size() > b.size()) ? a : b;
}

int main() {
    string s1 = "AFGBSR";
    string s2 = "FFGSRFGD";
    string result = lcsRec(s1, s2, s1.size(), s2.size());
    cout << "LCS = " << result << endl;
    cout << "LCS Length = " << result.size() << endl;
    return 0;
}

/*
LCS = FGSR
LCS Length = 4


*/
