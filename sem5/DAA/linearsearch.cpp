#include <iostream>
using namespace std;

int main() {
    int arr[5] = {13, 8, 15, 23, 42}; 
    int key = 23;
    int index = -1;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

//Output

//Element found at index 3
