#include <iostream>

class Base {
public:
    void show() {
        std::cout << "Base class show function called." << std::endl;
    }
};

class Derived1 : public Base {
public:
    void show() {
        std::cout << "Derived1 class show function called." << std::endl;
    }
};

class Derived2 : public Base {
public:
    void show() {               
        std::cout << "Derived2 class show function called." << std::endl;
    }
};

class Final : public Derived1, public Derived2 {
public:
    void display() {
        // This will cause ambiguity
        // show(); // Error: 'show' is ambiguous
        Derived1::show(); // Specify which one to call
        Derived2::show();
    }
};

int main() {
    Final obj;
    obj.display();
    return 0;
}
