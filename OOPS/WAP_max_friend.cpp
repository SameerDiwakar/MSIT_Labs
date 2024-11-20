#include <iostream>
using namespace std;
class a;
class b;
class a{
    private:
        int first;
    public:
        a(int num){
            first = num;
        }

    friend int max(a &one,  b &two);
    friend void swap(a &one, b &two);
    void change(b &sec){
        sec.second = 10;
    }

};
class b{
    private:
        int first;
        int second;
    public:
        b(int num){
            first = num;
        }

    friend int max(a &one,  b &two);
    friend void swap(a &one, b &two);
    friend class a;

};
int max(a &one, b &two){
    return (one.first > two.first) ? one.first : two.first;
}
void swap(a &one, b &two){
    int temp = one.first;
    one.first = two.first;
    two.first = temp;
}
int main() {
    a obj1(5);
    b obj2(3);
    cout <<" Larger of 2 numbers is : "<< max(obj1,obj2);
    cout <<  "After swapping " ;

    return 0;
}
