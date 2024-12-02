#include<iostream>
#include<string>
using namespace std;
class Address{
    string addressline;
    string city;
    string state;
    public:
    Address(){}
    Address(string addressline,string city,string state):addressline(addressline),city(city),state(state){

    }
    void display(){
        cout<<"Address line:"<<addressline<<endl;
        cout<<"City:"<<city<<endl;
        cout<<"State:"<<state<<endl;
    }
};
class Employee{
    Address *address;
    string name;
    string id;
    public:
    Employee(){}
    Employee(Address &address,string name,string id){
        this->address=&address;
        this->name=name;
        this->id=id;
    }

    void display2(){
        cout<<"Name:"<<name<<endl;
        cout<<"ID:"<<id<<endl;
        address->display();

    }
};
int main(){
    Address a1("SHAH RAHE FAISAL","KARACHI","Sindh");
    Employee e1(a1,"Urooj","23K-0071");
    cout<<"Employee Details:"<<endl;
    e1.display2();
}