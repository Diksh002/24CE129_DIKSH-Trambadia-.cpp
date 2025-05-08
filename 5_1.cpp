#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Calculator cal;
    int choice;

    cout << "1. Add integers\n";
    cout << "2. Add floating-point numbers\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int n1, n2;
        cout << "Enter two integers: ";
        cin >> n1 >> n2;
        cout << "Sum: " << cal.add(n1, n2) << endl;
    } else if (choice == 2) {
        float f1, f2;
        cout << "Enter two floats: ";
        cin >> f1 >> f2;
        cout << "Sum: " << cal.add(f1, f2) << endl;
    } else {
        cout << "Invalid choice.\n";
    }

    cout<<"\n\n"<<"24CE129_DIKSH Trambadia";
    return 0;
}