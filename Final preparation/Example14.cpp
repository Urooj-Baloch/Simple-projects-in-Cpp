#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNum;
    double balance;

public:
    BankAccount(string accNum, double bal) : accountNum(accNum), balance(bal) {}

    virtual void WithdrawAmount() {
        double wAmount;
        cout << "Enter amount to withdraw: ";
        cin >> wAmount;
        if (wAmount <= balance) {
            balance -= wAmount;
            cout << "Amount withdrawn! Remaining balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void DepositAmount() {
        double dAmount;
        cout << "Enter amount to deposit: ";
        cin >> dAmount;
        balance += dAmount;
        cout << "Amount deposited! New balance: " << balance << endl;
    }

    virtual void ApplyMonthlyCharges() = 0;

    double getBalance() const {
        return balance;
    }

    virtual void display() const {
        cout << "Account Number: " << accountNum << ", Balance: " << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;
    double minBalance;

public:
    SavingsAccount(string accNum, double bal, double rate, double minBal)
        : BankAccount(accNum, bal), interestRate(rate), minBalance(minBal) {}

    void ApplyMonthlyCharges() override {
        if (balance >= minBalance) {
            balance += (balance * interestRate);
            cout << "Interest applied! New balance: " << balance << endl;
        } else {
            cout << "Balance below minimum. No interest applied." << endl;
        }
    }
};

class CurrentAccount : public BankAccount {
    double maintenanceFee;

public:
    CurrentAccount(string accNum, double bal, double fee)
        : BankAccount(accNum, bal), maintenanceFee(fee) {}

    void ApplyMonthlyCharges() override {
        balance -= maintenanceFee;
        cout << "Maintenance fee deducted! New balance: " << balance << endl;
    }
};

class Customer {
    string name;
    string contact;
    string id;
    BankAccount* account;

public:
    Customer(string n, string c, string i, BankAccount* acc)
        : name(n), contact(c), id(i), account(acc) {}

    void ViewTransaction() {
        cout << "Customer Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "ID: " << id << endl;

        int choice;
        cout << "\nChoose an option:\n";
        cout << "1. Withdraw Money\n";
        cout << "2. Deposit Money\n";
        cout << "3. Check Balance\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account->WithdrawAmount();
                break;
            case 2:
                account->DepositAmount();
                break;
            case 3:
                cout << "Current balance: " << account->getBalance() << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    void ApplyCharges() {
        account->ApplyMonthlyCharges();
    }
};

int main() {
    SavingsAccount sa("SA123", 1000.0, 0.05, 500);
    Customer cust("John Doe", "123456789", "C001", &sa);

    int run = 1;
    while (run) {
        cust.ViewTransaction();

        cout << "\nDo you want to perform another operation? (1 for Yes, 0 for No): ";
        cin >> run;
    }

    cout << "\nApplying monthly charges...\n";
    cust.ApplyCharges();

    return 0;
}
