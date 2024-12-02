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
    int main(){
        Car c1("34f00892d","car","good","audi","black");
        c1.display();
        
    }
        
