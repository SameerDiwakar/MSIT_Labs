#include <iostream>
using namespace std;
class newclass{
    public:
    int num;
    newclass(int num){
        this->num = num;
    }
    newclass operator+(newclass &obj2){
        this->num += obj2.num;
        return *this;
    }
};
int main() {
    newclass o1(4),o2(56);
    o1+o2;
    cout << o1.num << " ";
    
    return 0;
}
