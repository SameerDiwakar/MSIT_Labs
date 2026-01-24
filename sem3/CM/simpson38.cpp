#include <iostream>
#include <vector>
using namespace std;

double simpson38rule(vector<double>&x,vector<double> y,int n){
    double integral =0.0;
    double h= x[1]-x[0];
    for (int i = 0 ; i < n ;i++){
        if (i == 0 || i == n-1){
            integral += y[i];
        }else if (i % 3 == 0){
            integral += 2 * y[i];
        }else{
            integral += 3*y[i];
        }
    }
    return integral*3*h/8;
}
// Function to compute the integral using the Trapezoidal Rule
double simpson3eightRule(const vector<double>& x, const vector<double>& y, int n) {
    double integral = 0.0;

    // Apply trapezoidal rule by summing up the areas of trapezoids
    double h =  x[1]-x[0];
    for (int i = 1; i < n - 1; i++) { // width of the trapezoids
        if (i%3 == 0){
            integral += 2*y[i];
        }else{
            integral += 3*y[i];
        } // area of trapezoid
    }
    integral += (y[0]+y[n-1]);

    return integral*3*h/8;
}

int main() {
    int n;
    cout << "Enter the number of data points for simpson 3/8th rule , n-1 should be a multiple of 3: ";
    
    cin >> n;
    if((n-1)%3!=0){
        cout<< "Error: no. of data points must be odd";
        return 0;
    }

    vector<double> x(n), y(n);
    cout << "Enter values of x: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    
    cout << "Enter values of y: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Calculating integral using Trapezoidal Rule
    double result = simpson3eightRule(x, y, n);

    cout << "The approximate value of the integral is: " << result << endl;
    cout << simpson38rule(x, y, n);

    return 0;
}