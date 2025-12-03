#include <iostream>
using namespace std;

void search(string pat, string txt) {
    int M = pat.size();
    int N = txt.size();

    for (int i = 0; i <= N - M; i++) {
        int j = 0;
        while (j < M && txt[i + j] == pat[j])
            j++;
        if (j == M)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string txt = "GERERGERSDRGER";
    string pat = "RGER";
    search(pat, txt);
    return 0;
}


// Pattern found at index 4
// Pattern found at index 10
