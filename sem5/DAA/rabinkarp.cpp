#include <iostream>
#include <cstring>
using namespace std;

#define d 256 // number of characters in input alphabet

void rabinKarp(char pat[], char txt[], int q) {
    int m = strlen(pat);
    int n = strlen(txt);
    long long p = 0; 
    long long t = 0; 
    long long h = 1;
 
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
  
        if (p == t) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << "Pattern found at index " << i << endl;
        }
 
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    char text[] = "GERERGERSDRGER";
    char pattern[] = "RGER";
    rabinKarp(pattern, text, 101);
    return 0;
}

// Pattern found at index 4
// Pattern found at index 10

