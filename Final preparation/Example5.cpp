#include<iostream>
#include<string>
using namespace std;
class Vehicle{
    public:
    string platnum;
    string type;
    string enginCondition;
    Vehicle(string platnum,string type,string enginCondition){
        this->platnum=platnum;
        this->type=type;
        this->enginCondition=enginCondition;
    }
    Vehicle(){}
    virtual void display(){
        cout<<"Plat number: "<<platnum<<endl;
        cout<<"Type: "<<type<<endl;
        cout<<"Engin condition: "<<enginCondition<<endl;
    }


    };
    class Car : public Vehicle{
        public:
        string model;
        string color;
        public:
        Car(){}
        Car(string platnum,string type,string enginCondition,string model,string color){
            this->platnum=platnum;
            this->type=type;
            this->enginCondition=enginCondition;
            this->model=model;
            this->color=color;
        }

    void display()override{
            Vehicle::display();
            cout<<"Model: "<<model<<endl;
            cout<<"Color: "<<color<<endl;
        }
    };
    class ElectCar : public Car{ 
       int  capacity;
       public:
       ElectCar(){}
       ElectCar(string platnum,string type, string enginCondition, string model,string color, int capacity){
        this->platnum=platnum;
            this->type=type;
            this->enginCondition=enginCondition;
            this->model=model;
            this->color=color;
            this->capacity=capacity;
       }
       void display()override{
        Car::display();
        cout<<"Battery capacity: "<<capacity<<endl;
       }

    };
    int main(){
        ElectCar c1("34f00892d","car","good","audi","black",1000);
        c1.display();
        
    }
        
