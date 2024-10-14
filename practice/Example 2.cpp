//association:
#include<iostream>
#include<string>
using namespace std;
class Address{
    string street;
    string house_num;
    int street_num;
    public:
    Address(){}
    Address(string street,string house_num,int street_num){
        this->street=street;
        this->house_num=house_num;
        this->street_num=street_num;
    }
    void display1(){
        cout<<"Street:"<<street<<endl;
        cout<<"House Number:"<<house_num<<endl;
        cout<<"Street Number:"<<street_num<<endl;
    }
};
class Names{
    Address address;
    string name;
    int age;
    public:
    Names(){}
    Names(Address address, string name, int age){
        this->address=address;
        this->name=name;
        this->age=age;
    }
    void display2(){
        address.display1();
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }
};
int main(){
    Address a1("Shah latif town","12a",19);
    Names n1(a1,"urooj",19);
    n1.display2();
}