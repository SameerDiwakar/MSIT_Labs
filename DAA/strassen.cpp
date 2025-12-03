#include <iostream>
using namespace std;

int main() {
    int x[2][2] = { {100, 4}, {242, 328} };
    int y[2][2] = { {323, 412}, {248, 182} };
    int z[2][2];

    int m1 = (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
    int m2 = (x[1][0] + x[1][1]) * y[0][0];
    int m3 = x[0][0] * (y[0][1] - y[1][1]);
    int m4 = x[1][1] * (y[1][0] - y[0][0]);
    int m5 = (x[0][0] + x[0][1]) * y[1][1];
    int m6 = (x[1][0] - x[0][0]) * (y[0][0] + y[0][1]);
    int m7 = (x[0][1] - x[1][1]) * (y[1][0] + y[1][1]);

    z[0][0] = m1 + m4 - m5 + m7;
    z[0][1] = m3 + m5;
    z[1][0] = m2 + m4;
    z[1][1] = m1 - m2 + m3 + m6;

    cout << "The first matrix is:\n";
    cout << x[0][0] << "\t" << x[0][1] << "\n";
    cout << x[1][0] << "\t" << x[1][1] << "\n";

    cout << "The second matrix is:\n";
    cout << y[0][0] << "\t" << y[0][1] << "\n";
    cout << y[1][0] << "\t" << y[1][1] << "\n";

    cout << "Product achieved using Strassen's algorithm:\n";
    cout << z[0][0] << "\t" << z[0][1] << "\n";
    cout << z[1][0] << "\t" << z[1][1] << "\n";

    return 0;
}
// The first matrix is:
// 100    4
// 242    328
// The second matrix is:
// 323    412
// 248    182
// Product achieved using Strassen's algorithm:
// 33292   41608
// 159510  133160
