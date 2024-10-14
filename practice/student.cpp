#include<iostream>
#include<string>
using namespace std;
class Student{
    string name;
    int age;
    string id;
    public:
    Student(){

    }
    Student(string name, int age, string id){
        this->name=name;
        this->age=age;
        this->id=id;
    }
    void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"id:"<<id<<endl;
    }

};
class course{
    Student student[5];
    int no_of_students;
    string course_name;
    string course_code;
    public:
    course(){

    }
    course(Student student,string course_name,string course_code){
        this->student[0]=student;
        this->no_of_students=1;
        this->course_name=course_name;
        this->course_code=course_code;
    }
    void add(Student new_student){
        
        if(no_of_students>0 && no_of_students<5){
            
            student[no_of_students] = new_student;
            no_of_students++;
        }
        else{
            cout<<"New student cant be added"<<endl;
        }
    }
    void displayStudents(){
        cout<<"no_of_students:"<<no_of_students<<endl;
        cout<<"Course name:"<<course_name<<endl;
        cout<<"Course code:"<<course_code<<endl;
        
        for (int i = 0; i < no_of_students; i++) {
            this->student[i].display(); 
        }
    
    }
};
int main(){
    Student s1("Urooj",19,"23k-0071");
    
    course c1(s1,"calculus","cs2001");
    
c1.add(Student("Mahnoor",19,"23k-0051"));

 
    c1.displayStudents();


    
}