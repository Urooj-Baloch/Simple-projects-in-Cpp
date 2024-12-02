#include<iostream>
using namespace std;
class Account{
    int balance;
    public:
    Account(int balance):balance(balance){}
    friend void showBalance(const Account &acc);
    friend class Auditor;
};
void showBalance(const Account &acc){
    cout<<"Balance: "<<acc.balance<<endl;
}
class Auditor{
    public:
    void display(const Account&acc ){
    cout<<"Balance: "<<acc.balance<<endl;
    } 
};
int main(){
    Account a1(5000);
    showBalance(a1);
    Auditor ad;
    ad.display(a1);
}