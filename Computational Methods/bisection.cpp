#include <iostream>
#include <cmath>
using namespace std;
int i = 0;
double ans;
double f(double n){
    return n * exp(n) - 3;
}

double bisect(double a, double b, int digit){
    double ans = (a+b)/2;
    if(abs(a-b) < pow(10,-digit)) return ans;
    if (f(a)*f(ans) < 0){
        cout << i++ << ":" << ans << endl;
        bisect(a,ans,digit);
    }else{
        cout << i++ << ":" << ans << endl;
        bisect(ans,b,digit);
    }
    return ans;
}
int main(){
    double a = bisect(-1,2,5);
    cout << "final: "<< a << endl;
}