#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds in your account.";
    }
};

class NegativeDepositException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Deposit amount cannot be negative.";
    }
};

class BankAccount {
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount < 0) {
            throw NegativeDepositException(); // Throw exception if deposit is negative
        }
        balance += amount;
        cout << "Successfully deposited " << amount << ". New balance: " << balance << endl;
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException(); // Throw exception if not enough funds
        }
        balance -= amount;
        cout << "Successfully withdrew " << amount << ". New balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(1000.0); // Create a bank account with an initial balance of $1000

    try {
        account.deposit(500.0); // Try to deposit $500
        account.withdraw(2000.0); // Try to withdraw $2000 (which is more than the balance)
    } 
    catch (const InsufficientFundsException& e) {
        cout << "Error: " << e.what() << endl; // Handle insufficient funds error
    }
    catch (const NegativeDepositException& e) {
        cout << "Error: " << e.what() << endl; // Handle negative deposit error
    }
    catch (const std::exception& e) {
        cout << "Unexpected error: " << e.what() << endl; // Catch any other unexpected errors
    }

    cout << "Final balance: " << account.getBalance() << endl;

    return 0;
}
