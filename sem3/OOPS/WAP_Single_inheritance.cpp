// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class car{
    private:
    double torque;
    public:
    int speed;
    string brand;
    car(int speed,string brand){
        this->speed = speed;
        this->brand = brand;
    }
    ~car(){
        cout<<"Car is destroyed"<<endl;
    }
    car(){
        cout<<"Car is created"<<endl;
    }
    
};
class Truck : public car{
    public:
    string trucktype;
    void getTruck(){
        cout <<"Truck Brand: " << brand << " " << "Truck Type: " <<trucktype;
    }
    Truck(int speed, string brand,string trucktype) : car(speed,brand){
        this->trucktype = trucktype;
    }
    ~Truck(){
        cout << "Fucked the truck";
    }
    Truck() : car(){
        cout << "Truck is created";
    }
};
int main() {
    Truck Mahi(120,"TechMahindra","Container");
    Truck::car mahi(29,"egg");
    cout << mahi.speed;
    car v(240,"Volvo");
    Mahi.getTruck();
    
}

//doubts : constructor calls using :: to base class what does it initiate ?
