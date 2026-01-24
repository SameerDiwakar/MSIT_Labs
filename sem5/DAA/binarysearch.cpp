#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 8, 15, 23, 42};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 23;
    int low = 0, high = n - 1;
    int index = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            index = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

//Element found at index 3
