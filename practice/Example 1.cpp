#include <iostream>  
using namespace std;
class Rectangle {
    int l;
    int w;
public:
    Rectangle() {}  
    Rectangle(int l, int w) {
        this->l = l;
        this->w = w;
    }
    int area() {
        return l * w;
    }
    int perimeter() {
        return 2 * (l + w);
    }
    void modify(int l, int w) {
        this->l = l;
        this->w = w;
    }
    void display() {
        cout << "Length: " << l << endl;
        cout << "Width: " << w << endl;
    }
};
void callToModifiedElements(Rectangle* rectptr, int l, int w) {
    rectptr->modify(l, w);
    cout << "Modified elements" << endl;
    rectptr->display();
}
int main() {
    Rectangle* rectptr = new Rectangle(5, 10);
    rectptr->display();
    cout << "Area: " << rectptr->area() << endl;
    cout << "Perimeter: " << rectptr->perimeter() << endl;

    callToModifiedElements(rectptr, 20, 12);
    cout << "Area: " << rectptr->area() << endl;
    cout << "Perimeter: " << rectptr->perimeter() << endl;

    return 0;
}
