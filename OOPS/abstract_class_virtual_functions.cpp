#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  // This makes the class abstract

    // Virtual destructor
    virtual ~Shape() {
        cout << "Shape destroyed." << endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {  // Override the pure virtual function
        cout << "Drawing a Circle." << endl;
    }

    ~Circle() {
        cout << "Circle destroyed." << endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {  // Override the pure virtual function
        cout << "Drawing a Rectangle." << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destroyed." << endl;
    }
};

int main() {
    // Pointers to abstract base class (polymorphism)
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Calls Circle's draw method
    shape2->draw();  // Calls Rectangle's draw method

    // Clean up memory
    delete shape1;
    delete shape2;

    return 0;
}
