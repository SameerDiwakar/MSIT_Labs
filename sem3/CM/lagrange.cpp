#include <bits/stdc++.h>
using namespace std;

struct Data{
    int x,y;
};

double interpolate(Data table[],int xi, int n){
    double ans = 0;
    for (int i = 0 ; i < n ; i++){
        double term = table[i].y;
        for (int j = 0 ; j < n ; j++){
            if (j != i){
                term = term * (xi - table[j].x) / double((table[i].x -table[j].x));
            }
    }
    
            ans+=term;
    }
    return ans;
}

int main(){
    Data table[] = {{0,4},{2 ,26},{3,58},{4,112},{7,466}};
    cout << "Value of f(5) is" << interpolate(table,5,5)<<endl;
    return 0;
}