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
    
    return 0;
}
