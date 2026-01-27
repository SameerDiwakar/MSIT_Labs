#include <iostream>
using namespace std;

int fib(int a){
    if (a == 0 || a == 1){
        return 1;
    }
    int f = a*fib(a-1);
    return f;

}
int main(){
    int a;
    cin >> a;
    int res = 1;
    for (int i  = 1 ;i <= a ;i++){
        res*=i;
    }
    cout << res;
    cout << fib(a);
}