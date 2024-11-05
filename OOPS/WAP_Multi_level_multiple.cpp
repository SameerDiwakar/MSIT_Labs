#include <iostream>
using namespace std;

// Base class 1
class Animal {
public:
    Animal() {
        cout << "Animal constructor called." << endl;
    }
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Base class 2
class Bird {
public:
    Bird() {
        cout << "Bird constructor called." << endl;
    }
    void fly() {
        cout << "Bird can fly." << endl;
    }
};

// Derived class (Multiple Inheritance)
class Bat : public Animal, public Bird {
public:
    Bat() {
        cout << "Bat constructor called." << endl;
    }
    void sound() {
        cout << "Bat makes sound." << endl;
    }
};

// Base class for Multilevel Inheritance
class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle constructor called." << endl;
    }
    void start() {
        cout << "Vehicle started." << endl;
    }
};

// Derived class 1 (Multilevel Inheritance)
class Car : public Vehicle {
public:
    Car() {
        cout << "Car constructor called." << endl;
    }
    void honk() {
        cout << "Car honks!" << endl;
    }
};

// Derived class 2 (Multilevel Inheritance)
class ElectricCar : public Car {
public:
    ElectricCar() {
        cout << "ElectricCar constructor called." << endl;
    }
    void charge() {
        cout << "Electric car is charging." << endl;
    }
};

int main() {
    // Demonstrating Multiple Inheritance
    cout << "Creating Bat object:" << endl;
    Bat bat;
    bat.eat();  // Inherited from Animal
    bat.fly();  // Inherited from Bird
    bat.sound();  // Specific to Bat
    cout << endl;

    // Demonstrating Multilevel Inheritance
    cout << "Creating ElectricCar object:" << endl;
    ElectricCar electricCar;
    electricCar.start();  // Inherited from Vehicle
    electricCar.honk();  // Inherited from Car
    electricCar.charge();  // Specific to ElectricCar
    cout << endl;

    return 0;
}
