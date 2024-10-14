#include<iostream>
#include<string>
using namespace std;
class Course{
      string name;
      string course_code;
      public:
      Course(){

      }
      Course(string name,string course_code){
        this->name=name;
        this->course_code=course_code;
      }
      void display1(){
        cout<<"Course Name:"<<name<<endl;
        cout<<"Course Code:"<<course_code<<endl;
      }

};
class Department{
      Course course;
      string depName;
      public:
      Department(){

      }
      Department(Course course,string depName){
        this->course=course;
        this->depName=depName;
      }
      void display2(){
        course.display1();
        cout<<"Department Name:"<<depName<<endl;
      }
};
class University{
    Department* dept1;
    Department* dept2;
    public:
    University(){}
    University(Department* dept1, Department* dept2){
        this->dept1=dept1;
        this->dept2=dept2;
    }
    void display3(){
        if(dept1){
            dept1->display2();
        }
        if(dept2){
            dept2->display2();
        }
    }
};
int main(){
    Course c1("Calculus","23s0091");
    Course c2("Discrete","Cs0043");
    Department dept1(c1,"CS");
    Department dept2(c2,"SE");
    University uni(&dept1,&dept2);
    uni.display3();
}