#include<iostream>
#include<string>
using namespace std;
class Book{
    static int count;
    string title;
    string author;
    int prize;
    public:
    Book(){}
    Book(string title, string author,int prize){
        this->title=title;
        this->author=author;
        this->prize=prize;
        count++;
    }
    static int getcount(){
        return count;
    }
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Prize: "<<prize<<endl;
        
    }

};
int Book::count=0;

int main(){
    Book b1("Halim","Nimra",2500);
    Book b2("Mala","Nimra",3000);
    Book b3("Yaram","Sameera",2000);
    b1.display();
    b2.display();
    b3.display();
cout<<"Number of objects made: "<<Book::getcount()<<endl;

}