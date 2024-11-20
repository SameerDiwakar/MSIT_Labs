#include <iostream>
using namespace std;

// Base class: Vehicle
class Vehicle {
public:
    // Virtual method
    virtual void display() {
        cout << "This is a vehicle." << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
public:
    // Overriding the display method
    void display() override {
        cout << "This is a car." << endl;
    }
};

int main() {
    Vehicle* vehicle;
    Car car;

    // Base class pointer pointing to a Car object
    vehicle = &car;
    vehicle->display();
    car.display();  // Calls Car's overridden method

    return 0;
}
