#include <iostream>
using namespace std;

#define PI 3.14159265358979323846

class Shape {
protected:
    double Area;

    virtual void Calculate_area() = 0;

    void Display() {
        cout << "Area: " << Area << " sq. units";
    }

public:
    virtual ~Shape() {}

    void ShowArea() {
        Display();
    }
};

class Rectangle : public Shape {
    double Length, Width;

    void Calculate_area() override {
        Area = Length * Width;
    }

public:
    Rectangle(double l, double w) : Length(l), Width(w) {
        Calculate_area();
    }
};

class Circle : public Shape {
    double Radius;

    void Calculate_area() override {
        Area = PI * Radius * Radius;
    }

public:
    Circle(double r) : Radius(r) {
        Calculate_area();
    }
};

int main() {
    int Choice;
    double a, b;

    while (true) {
        cout << "-~Area Calculator~-"
             << "\nEnter 1 for Circle, 2 for Rectangle, 0 to Exit"
             << "\nEnter Choice: ";
        cin >> Choice;

        if (Choice == 1) {
            cout << "Enter Circle Radius: ";
            cin >> a;
            Shape* shape = new Circle(a);
            shape->ShowArea();
            delete shape;
        } else if (Choice == 2) {
            cout << "Enter Rectangle Length: ";
            cin >> a;
            cout << "Enter Rectangle Width: ";
            cin >> b;
            Shape* shape = new Rectangle(a, b);
            shape->ShowArea();
            delete shape;
        } else if (Choice == 0) {
            cout << "Exiting System...\n";
            break;
        } else {
            cout << "Invalid Choice. Try again.";
        }
    }

    cout<<"\n\n"<<"24CE129_DIKSH Trambadia";

    return 0;
}