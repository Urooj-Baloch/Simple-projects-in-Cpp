#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void rules(){
    cout<<"\n\n";
    cout<<"WELCOME TO CASSINO"<<endl;
    cout<<"_____________________________________________________________"<<endl;
    cout<<"RULES:"<<endl;
    cout<<"\n";
    cout<<"If you win you will get 5 times of your betting amount"<<endl;
    cout<<"If you lose you will lose your betted amount"<<endl;
    cout<<"No one will be responsable for your lose play at your own risk"<<endl;
    cout<<"This is the game of luck. Best of luck"<<endl;
    cout<<"______________________________________________________________"<<endl;
}
int main(){
    int betting_amount;
    int deposit_amount;
    string name;
    int guess_num;
    int dice;
    char choice;
     srand(time(0));
      rules(); 
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"Enter the amount you have: "<<endl;
    cin>>deposit_amount;
    cout<<"Your deposited amount is "<<deposit_amount<<endl;
    cout<<"Are you sure you want to play y/n"<<endl;
        cin>>choice;
        if(choice=='y'||choice=='Y'){
    do{

       cout<<"Enter the amount you want to bet:"<<endl;
       cin>>betting_amount;
       if(betting_amount>deposit_amount){
        cout<<"The betting amount is more then your present amount"<<endl;
       } 
       while(betting_amount>deposit_amount);
       do{
         cout<<"Guess the number from 1 to 10 "<<endl;
         cin>>guess_num;
         if(guess_num>10||guess_num<0){
         cout<<"Enter the number between 1 to 10"<<endl;
       }
       }
       while(guess_num>10||guess_num<0);
       dice = rand()%10 + 1;
       if(dice==guess_num){
        cout<<"You won"<<endl;
        betting_amount=betting_amount*5;
        cout<<"Your winning amount is  "<<betting_amount<<endl;
        deposit_amount+=betting_amount;
        cout<<"Total amount after winning "<<deposit_amount<<endl;
       }
       else{
        cout<<"You lose. The winning number was "<<dice<<endl;
        deposit_amount=deposit_amount-betting_amount;
        cout<<"You lose the amount "<<betting_amount<<endl;
        cout<<"Now your current deposited amount is "<<deposit_amount<<endl;
       }
       if(deposit_amount==0){
        cout<<"You have no money to play again."<<endl;
        cout<<"BETTER LUCK NEXT TIME!"<<endl;
        break;
       }
       cout<<"Do you want to play again [click y or Y for 'yes'] and [click n or N for no] "<<endl;
       cin>>choice;
       cout<<"THANK YOU FOR PLAYING AGAIN\n";
    }
    while(choice=='y'||choice=='Y');
    }


}