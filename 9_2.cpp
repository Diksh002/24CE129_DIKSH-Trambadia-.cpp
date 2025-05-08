#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string name, double initialDeposit = 0.0) 
        : accountHolder(name), balance(initialDeposit) {}

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Deposit failed: Invalid amount.");
            cout << "Deposit failed: Invalid amount." << endl;
        } else {
            balance += amount;
            logTransaction("Deposited: " + to_string(amount));
            cout << "Deposited: " << amount << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Withdrawal failed: Invalid amount.");
            cout << "Withdrawal failed: Invalid amount." << endl;
        } else if (amount > balance) {
            logTransaction("Withdrawal failed: Insufficient funds.");
            cout << "Withdrawal failed: Insufficient funds." << endl;
        } else {
            balance -= amount;
            logTransaction("Withdrew: " + to_string(amount));
            cout << "Withdrew: " << amount << endl;
        }
    }

    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void displayTransactionHistory() {
        cout << "Transaction History: " << endl;
        for (const string& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }

private:
    void logTransaction(const string& message) {
        transactionHistory.push_back(message);
        ofstream logFile("transaction_log.txt", ios::app);
        if (logFile.is_open()) {
            logFile << accountHolder << " - " << message << endl;
            logFile.close();
        } else {
            cout << "Error logging transaction." << endl;
        }
    }
};

int main() {
    // Create bank account for user
    BankAccount account("John Doe", 500.0);

    // Display current balance
    account.displayBalance();

    // Deposit some money
    account.deposit(150.0);
    account.displayBalance();

    // Try withdrawing an invalid amount
    account.withdraw(700.0);  // Overdraft attempt
    account.displayBalance();

    // Withdraw a valid amount
    account.withdraw(200.0);
    account.displayBalance();

    // Display transaction history
    account.displayTransactionHistory();

    return 0;
}