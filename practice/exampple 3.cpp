//aggregation:
#include <iostream>
#include <string>
using namespace std;

class Address {
    string street;
    string house_num;
    int street_num;
public:
    Address(string street, string house_num, int street_num) {
        this->street = street;
        this->house_num = house_num;
        this->street_num = street_num;
    }
    void display() {
        cout << "Street: " << street << endl;
        cout << "House Number: " << house_num << endl;
        cout << "Street Number: " << street_num << endl;
    }
};

class Names {
    string name;
    int age;
public:
    Names(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void displayAddress(Address &adr) {  // Accepts a reference to Address
        cout << "Address Detail:" << endl;
        adr.display();  // Calls display on the Address object
    }
};

int main() {
    Address a1("Shah Latif Town", "12a", 19);
    Names n1("Urooj", 19);
    n1.displayAddress(a1);  // Passes the Address object by reference
}
