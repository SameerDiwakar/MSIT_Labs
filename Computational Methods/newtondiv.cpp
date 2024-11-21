#include <iostream>
using namespace std;

float proterm(int i, float value, float x[]){
    float pro = 1;
    for (int j = 0; j < i ; j++){
        pro = pro*(value - x[j]);
    }
    return pro;
}
float applyFormula(float value, float x[],float y[][10],int n){
    float sum = y[0][0];
    for (int i = 1 ; i < n ; i++){
        sum += proterm(i,value,x)*y[0][i];
    }
    return sum;
}
void divdiff(float x[],float y[][10],int n){
    for (int i = 1; i < n ;i++){
        for (int j = 0; j < n-i ; j++ ){
            y[j][i] = (y[j+1][i-1] - y[j][i-1]) / (x[j+i]-x[j]); 
        }
    }
}
void printTable(float y[][10],float x[],int n){
    for (int i = 0;  i < n ; i++){
        for (int j = 0 ; j < n - i ;j++){
            cout << y[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    float value, sum, y[10][10];
    float x[] = {-4,-1,0,2,5};
    y[0][0] = 1245;
    y[1][0] = 33;
    y[2][0] = 5;
    y[3][0] = 9;
    y[4][0] = 1335;
    divdiff(x,y,n);
    printTable(y,x,n);
    value = 1;
    cout << "\n Value at " << value << "is " << applyFormula(value,x,y,n);
    return 0;
}