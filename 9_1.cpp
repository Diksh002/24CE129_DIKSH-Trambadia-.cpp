#include <iostream>
#include <limits>

using namespace std;

int main() {
    double loanAmount, annualIncome;

    cout << "Enter loan amount: ";
    while (!(cin >> loanAmount) || loanAmount < 0) {
        cout << "Invalid input. Please enter a positive number for loan amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter annual income: ";
    while (!(cin >> annualIncome) || annualIncome <= 0) {
        if (annualIncome == 0)
            cout << "Annual income cannot be zero. Please enter a valid number: ";
        else
            cout << "Invalid input. Please enter a positive number for income: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double ratio = loanAmount / annualIncome;
    cout << "Loan-to-Income Ratio: " << ratio << endl;

    return 0;
}