#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double f(double x){
    double h = x*exp(x) - cos(x);
    return h;
}

void secant(double x1,double x2, double E){
    double n = 1, x0,xm,c;
    if (f(x1)*f(x2) < 0){
        do{
            x0 = (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
            c = f(x1)*f(x0);
            cout << "Iteration "<<n<<":" <<x0<<endl;
            x1 = x2;
            x2 = x0;
            if (c == 0)break;
            xm = (x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
            n++;
        }while(abs(xm-x0) >=E);
        cout << "Root of given equation= " << x0 << endl;
        cout << "No. of iterations= " << n-1 << endl;
    }else{
        cout<<"No root exists in the given interval"<<endl;
    }
}

int main(){
    double x1,x2,E = 0.0001;
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the value of x2: ";
    cin >> x2;
    secant(x1,x2,E);
    return 0;
}