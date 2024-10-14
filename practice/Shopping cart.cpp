#include<iostream>
#include<string>
using namespace std;
class Product{
    string name;
    float price;
    public:
    Product(){}
    Product(string name,float price){
        this->name=name;
        this->price=price;
    }
    void display1(){
        cout<<"Product Name:"<<name<<endl;
        cout<<"Price:"<<price<<endl;
    }
};
class Cart{
    Product product[5];
    int no_of_items=1;
    public:
    Cart(){}
    Cart(Product product){
        this->product[0]=product;
    }
    void AddProduct(Product newproduct){
        if(no_of_items<5){
            product[no_of_items]=newproduct;
            no_of_items++;
        }
        else{
            cout<<"New product can't be added! you can only add 5 items in your cart"<<endl;
        }
    }
    void display2(){
        for (int i = 0; i < no_of_items; i++) {
            this->product[i].display1(); 
        }

    }
};
int main(){
    Product p1("Washing machine",20000);
    Cart c1(p1);
    c1.AddProduct(Product("Dish Washer",300));
     c1.AddProduct(Product("Dry fruits",300));
     c1.AddProduct(Product(" Window Washer",300));
     c1.AddProduct(Product("Fish Washer",300));
     c1.AddProduct(Product("Surf Excel",300));
    
    c1.display2();
}