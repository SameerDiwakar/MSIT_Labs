#include <iostream>
using namespace std;
class Complex{
    int real,img;
    public:
    Complex(int r , int i){
        real = r;
        img = i;
    }
    Complex operator-(){
        return Complex(-real,-img);
    }
    void operator-(Complex obj1){
        this->real = (this->real) - (obj1.real);
    }
    void display(){
        cout << real << "+" << img<<"i";
    }
};

int main() {
    Complex c(3,4);
    Complex b = -c;
    cout << "Original Complex Number: ";
    c.display();
    cout<<endl;
    cout <<"Negated complex Number: ";
    b.display();
    b-c;
    cout << "Negated complex Number after subtraction: ";
    b.display();

    
    return 0;
}
//this one
