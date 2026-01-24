#include <iostream>
using namespace std;

double f(double x, double y){
    return 3*x*x + y*y;
}
double rungeKutta(double x0, double y0, double x, double h){
    int n = (x-x0)/h;
    double y = y0;
    for (int i = 0 ; i < n ; i++){
        double k1 = h*f(x0,y);
        double k2 = h*f(x0+h/2,y+k1/2);
        double k3 = h*f(x0+h/2,y+k2/2);
        double k4 = h*f(x0+h,y+k3);

        y = y + (k1+2*k2+2*k3 + k4 )/6;
        x = x0+h;
    }
    return y;
}

int main(){
    double x0,y0,h,x;
    cout << "Enter initial values of x and y" << endl;
    cin >> x0 >> y0;
    cout << "Enter step size" << endl;
    cin >> h;
    cout <<"Enter value of x at which you want y" << endl;
    cin >> x;

    double result = rungeKutta(x0,y0,x,h);
    cout << "The value of y at x = " << x << " is " << result <<endl;
    return 0;

}