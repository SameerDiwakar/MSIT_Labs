#include <iostream>
using namespace std;

int main() {
    try {
        int x = 0;
        if (x == 0) {
            throw "Division by zero error!";
        }
        cout << 10 / x << endl;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }
    
    return 0;
}
