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
    
};
class Truck : public car{
    public:
    string trucktype;
    void getTruck(){
        cout << brand << "T " <<trucktype;
    }
    Truck(int speed, string brand){
        car(a)
    }
};
int main() {
    Truck Mahi(120,"TechMahindra");
    Mahi.trucktype = "H1";
    car v(240,"Volvo");
    Mahi.getTruck();
    
}
