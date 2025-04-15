#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() { balance = 0; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        } else {
            cout << "Error: Either invalid amount or insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Account Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account;
    double amount;
    int choice;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    cout<<endl<<"24CE129_ DIKSH Trambadia";

    return 0;
}