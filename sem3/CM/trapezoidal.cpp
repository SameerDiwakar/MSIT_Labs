#include <iostream>
#include <vector>
using namespace std;

// Function to compute the integral using the Trapezoidal Rule
double trapezoidalRule(const vector<double>& x, const vector<double>& y, int n) {
    double integral = 0.0;

    // Apply trapezoidal rule by summing up the areas of trapezoids
    double h =  x[1]-x[0];
    for (int i = 1; i < n - 1; i++) { // width of the trapezoid
        integral += (y[i]); // area of trapezoid
    }
    integral += (y[0]+y[n-1])/2;

    return integral*h;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter values of x: ";
    for (int i = 0; i < n; i++) cin >> x[i];
    
    cout << "Enter values of y: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    // Calculating integral using Trapezoidal Rule
    double result = trapezoidalRule(x, y, n);

    cout << "The approximate value of the integral is: " << result << endl;

    return 0;
}