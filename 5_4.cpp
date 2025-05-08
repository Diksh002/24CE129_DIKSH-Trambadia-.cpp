#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;
public:
    Celsius(float t = 0) { temp = t; }
    float getTemp() { return temp; }

    operator Fahrenheit();
    bool operator==(Fahrenheit f);
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 0) { temp = t; }
    float getTemp() { return temp; }

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    bool operator==(Celsius c) {
        return ((temp - 32) * 5 / 9) == c.getTemp();
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

bool Celsius::operator==(Fahrenheit f) {
    return ((temp * 9 / 5) + 32) == f.getTemp();
}

int main() {
    float cTemp, fTemp;

    cout << "Enter temperature in Celsius: ";
    cin >> cTemp;
    Celsius c1(cTemp);
    Fahrenheit f1 = c1;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fTemp;
    Fahrenheit f2(fTemp);
    Celsius c2 = f2;

    if (c1 == f2)
        cout << "Temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    Fahrenheit fArray[2];
    fArray[0] = f1;
    fArray[1] = Fahrenheit(100);

    for (int i = 0; i < 2; i++) {
        cout << fArray[i].getTemp() << " F\n";
    }

    cout<<"\n\n"<<"24CE129_DIKSH Trambadia";

    return 0;
}