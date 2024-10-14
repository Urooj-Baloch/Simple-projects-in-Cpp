#include<iostream>
#include<string>
using namespace std;
class Author{
    string name;
    int age;
    public:
    Author(){
        
    }
    Author(string name,int age){
        this->name=name;
        this->age=age;
    }
    void displayAuthor(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }
    
};
class book{
    Author author;
    string title;
    string genre;
    public:
    book(){
        
    }
    book(Author author,string title,string genre){
        this->author=author;
        this->title=title;
        this->genre=genre;
    }
    void display(){
        author.displayAuthor();
        cout<<"Title:"<<title<<endl;
        cout<<"Genre:"<<genre<<endl;
    }
    
};

int main(){
    Author a1("Nimra Ahmed",25);
    book b1(a1,"halim","Fantasy");
    b1.display();
}