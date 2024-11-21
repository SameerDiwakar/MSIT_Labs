#include <iostream>
#include <cmath>

using namespace std;


double E = 0.00001;
double f(double x){
    return x*x*x - x - 1;
}
double df(double x){
    return 3*x*x - 1;
}
void nR(double x){
    double h = f(x)/df(x);
    int i = 1;
    while(abs(h) > E){
        h = f(x)/df(x);
        x = x-h;
        cout << "Iteration" << i++ << ":" << x << endl;
    }
    cout << "Value of root is "<<x << endl;
}
int main(){
    double a = 1.0;
    nR(a);
    return 0;

}