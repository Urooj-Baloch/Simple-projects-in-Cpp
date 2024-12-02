#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    static int id;
    static int sem;
    static float gpa;
 
    public:
    Student(){
       
    }
    Student(int id,int sem, float gpa){
        this->id=id;
        this->sem=sem;
        this->gpa=gpa;
    }
    void display(){
        cout<<"ID:"<<id<<endl;
        cout<<"SEMESTER:"<<sem<<endl;
        cout<<"Gpa:"<<gpa<<endl;
    }
};
int Student::id=10;
int Student::sem=3;
float Student::gpa=3.0;

int main(){
    Student s1;
    s1.display();
}