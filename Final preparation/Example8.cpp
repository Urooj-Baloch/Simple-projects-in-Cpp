#include<iostream>
using namespace std;
class Subtraction{
    int value;
    public:
    Subtraction(int value=0):value(value){}
    Subtraction &operator--(){
        --value;
        return *this;
    }
    Subtraction operator--(int){
        Subtraction temp=*this;
        value--;
        return temp;
    }
    void display()const{
        cout<<"Value: "<<value<<endl;
    }
};
int main(){
    Subtraction s(5);
    cout<<"Initial value: "<<endl;
    s.display();
    cout<<"Pre: "<<endl;
    s--;
    s.display();
    cout<<"Post: "<<endl;
    --s;
    s.display();
}