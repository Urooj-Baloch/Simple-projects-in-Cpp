#include <iostream>
using namespace std;

class Rupee {
    int data;
public:
    Rupee() : data(0) {}
    Rupee(int data) : data(data) {}

    // Unary minus operator overload
    Rupee operator-() {
        Rupee temp;
        temp.data = -data;
        return temp;
    }

    // Binary addition operator overload
    Rupee operator+(const Rupee &obj) {
        Rupee temp;
        temp.data = data + obj.data;
        return temp;
    }

    // Compound assignment (+=) operator overload
    Rupee& operator+=(const Rupee &obj) {
        data += obj.data;
        return *this;
    }

    // Compound assignment (-=) operator overload
    Rupee& operator-=(const Rupee &obj) {
        data -= obj.data;
        return *this;
    }

    // Friend function to overload << operator
    friend ostream& operator<<(ostream &os, const Rupee &e);
};

// Definition of the friend function
ostream& operator<<(ostream &os, const Rupee &e) {
    os << e.data;
    return os;
}

int main() {
    Rupee wholesale(20), retail;
    retail = wholesale;
    cout << "Wholesale: " << wholesale << endl << "Retail: " << retail << endl;

    Rupee discount(2);
    retail -= discount;
    cout << "Retail after discount: " << retail << endl;

    // Correct the wholesale assignment
    wholesale = Rupee(34);
    cout << "New wholesale: " << wholesale << endl;

    // Correct the addition with integer
    retail = wholesale + Rupee(10);
    cout << "Retail after addition: " << retail << endl;

    Rupee profit = retail + (-wholesale);
    cout << "Profit: " << profit << endl;

    profit = -profit;
    cout << "Profit after negation: " << profit << endl;

    return 0;
}
