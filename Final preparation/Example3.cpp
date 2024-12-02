#include<iostream>
#include<string>
using namespace std;
class Wheel{
    string color;
    int size;
    string condition;
    public:
    Wheel(){}
    Wheel(string color,int size,string condition){
        this->color=color;
        this->size=size;
        this->condition=condition;
    }
    void display(){
        cout<<"Color of wheels:"<<color<<endl;
        cout<<"Size of wheels:"<<size<<endl;
        cout<<"Condtition of wheels:"<<condition<<endl;
    }
};
class Car{
    Wheel wheel;
    string model;
    string YearOfManufacture;
    string carColor;
    public:
    Car(){}
    Car(Wheel wheel,string model,string YearOfManufacture,string carColor){
        this->wheel=wheel;
        this->model=model;
        this->YearOfManufacture=YearOfManufacture;
        this->carColor=carColor;
    }
    void displayCar(){
        cout<<"Model:"<<model<<endl;
        cout<<"Year of manufacture:"<<YearOfManufacture<<endl;
        cout<<"Color of Car:"<<carColor<<endl;
        wheel.display();
    }
};
int main(){
    Wheel w1("Black",2,"Good");
    Car c1(w1,"BMW","2024","red");
    c1.displayCar();
}