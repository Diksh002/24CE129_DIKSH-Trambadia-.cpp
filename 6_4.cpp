#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived Destructor\n";
    }
};

int main() {
    int choice;
    cout << "Enter 1 to create Derived object, 0 to exit: ";
    cin >> choice;

    if (choice == 1) {
        Base* ptr = new Derived();
        delete ptr;
    } else {
        cout << "Exiting...\n";
    }

    return 0;
}