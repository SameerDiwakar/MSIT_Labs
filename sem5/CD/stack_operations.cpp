#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 9;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
        } else {
            arr[++top] = x;
            cout << "Pushed " << x << " to stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
        } else {
            cout << "Popped " << arr[top--] << " from stack" << endl;
        }
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack S;

    S.push(10);
    S.push(20);
    S.push(30);
    S.display();

    cout << "Current size: " << S.size() << endl;

    S.pop();
    S.display();

    cout << "Is Empty? " << (S.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
