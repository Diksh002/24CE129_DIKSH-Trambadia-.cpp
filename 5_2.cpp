#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    friend istream& operator>>(istream &in, Complex &c) {
        cout << "Enter real and imaginary part: ";
        in >> c.real >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    Complex operator+(const Complex &b) {
        Complex temp;
        temp.real = real + b.real;
        temp.imag = imag + b.imag;
        return temp;
    }

    Complex operator-(const Complex &b) {
        Complex temp;
        temp.real = real - b.real;
        temp.imag = imag - b.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, sum, diff;
    cin >> c1;
    cin >> c2;
    sum = c1 + c2;
    diff = c1 - c2;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    cout<<"\n\n"<<"24CE129_DIKSH Trambadia";
    return 0;
}