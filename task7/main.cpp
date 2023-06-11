//
// fraction/main.cpp
//
#include "fraction.hpp"
#include "Mengde.hpp"
#include <iostream>
#include <string>

using namespace std;

Fraction operator-(int integer, const Fraction &other);

Fraction operator-(int integer, const Fraction &other) {
    Fraction fraction(integer, 1);
    fraction = fraction - other;
    return fraction;
}

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction fraction1(3, 2);
    Fraction fraction2(3, 4);

    Fraction fraction3 = fraction1 - 5;
    Fraction fraction4 = 5 - fraction1;

    print("fraction3 = ", fraction3);
    print("fraction4 = ", fraction4);


    print("5 - 3 - fraction1 - 7 - fraction2 = ", 5 - 3 - fraction1 - 7 - fraction2);

    cout << "Oppgave 2: " << endl;
    Mengde mengde1({1, 2, 3, 4, 5});
    Mengde mengde2({3, 4, 5, 6, 7});
    cout << "Printer ut mengdene: " << endl;
    ++mengde1;
    ++mengde2;

    cout << "Union av mengde 1 og 2:" << endl;
    mengde1 += mengde2;
    ++mengde1;

    cout << "Legger til 1 i mengde 2: " << endl;
    ++(mengde2 + 1);

    cout << "Setter mengde 1 til mengde 2: " << endl;
    mengde1 = mengde2;
    ++mengde1;
    ++mengde2;

    return 0;
}