#include<iostream>
using namespace std;
class Circle{
    int radius;
    public:
    Circle(int radius):radius(radius){}
    friend class Perimeter;
    
};

class Perimeter{
    public:
    Perimeter(){}
    Perimeter(const Circle &c){}
    void display(const Circle &c){
        const float pi=3.14;
        float perimeter=c.radius*2*pi;
        cout<<"Perimeter of circle: "<<perimeter<<endl;
    }

};
int main(){
    Circle c1(1);
    Perimeter p1;
    p1.display(c1);
}