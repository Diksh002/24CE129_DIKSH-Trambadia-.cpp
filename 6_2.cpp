#include <iostream>
using namespace std;

class Point {
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}

    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }
};

int main() {
    int x, y, dx, dy;

    cout << "Enter initial x and y coordinates: ";
    cin >> x >> y;
    Point p(x, y);
    p.display();

    cout << "Enter movement for x and y (dx, dy): ";
    cin >> dx >> dy;
    p.move(dx, dy)->display();

    cout << "Enter movement for x and y (dx, dy): ";
    cin >> dx >> dy;
    p.move(dx, dy)->display();

    return 0;
}