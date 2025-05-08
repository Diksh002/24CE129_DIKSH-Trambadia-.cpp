#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    void getInput() {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }

    void show() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    void operator-() {
        x = -x;
        y = -y;
    }

    bool operator==(Point p) {
        return x == p.x && y == p.y;
    }
};

int main() {
    Point A, B, C;

    A.getInput();
    B.getInput();

    C = A + B;
    cout << "Addition: ";
    C.show();

    -A;
    cout << "Negated A: ";
    A.show();

    if (A == B)
        cout << "Points are equal" << endl;
    else
        cout << "Points are not equal" << endl;

        cout<<"\n\n"<<"24CE129_DIKSH Trambadia";

    return 0;
}