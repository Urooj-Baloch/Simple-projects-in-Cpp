#include<iostream>
using namespace std;
class Rectangle{
    int length;
    int width;
    
    public:
    Rectangle(int length, int width):length(length),width(width){
    }
    friend int CalculateArea(const Rectangle &r);
};
int CalculateArea(const Rectangle &r){
    int area=r.length*r.width;
    cout<<"Area: "<<area<<endl;
}
int main(){
    Rectangle r1(2,2);
    CalculateArea(r1);
}