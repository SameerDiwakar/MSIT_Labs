#include <iostream>
using namespace std;

int main() {
    int arr[] = {42, 23, 15, 8, 3};   
    int n = sizeof(arr) / sizeof(arr[0]);

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) 
                minIdx = j;
        }

        swap(arr[minIdx], arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

/*
Output:
3 8 15 23 42
*/
