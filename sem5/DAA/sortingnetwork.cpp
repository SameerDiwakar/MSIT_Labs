#include <bits/stdc++.h>
using namespace std;

void compSwap(int &a, int &b, bool dir) {
    if (dir == (a > b))
        swap(a, b);
}

void bitonicMerge(vector<int> &arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compSwap(arr[i], arr[i + k], dir);
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void bitonicSort(vector<int> &arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(arr, low, k, true);
        bitonicSort(arr, low + k, k, false);
        bitonicMerge(arr, low, cnt, dir);
    }
}

int main() {
    // Input array size should be a power of 2 for bitonic sort
    vector<int> arr = {14, 53, 45, 6, 2, 4, 6, 8}; 
    bitonicSort(arr, 0, arr.size(), true);

    cout << "Sorted Output:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
//Sorted Output:
//2 4 6 6 8 14 45 53 
