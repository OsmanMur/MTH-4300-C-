#include "rational.h"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main(){
    // Test constructor/reduce()
    Rational a(6, 8);
    cout << "TEST constructor/reduce(): the following should be 3 / 4: " << a << endl;
    
    // Test +=
    Rational b(3, 2);
    b += Rational(-1, 3);
    cout << "TEST +=: the following should be 7 / 6: " << b << endl;

    // Test -=
    Rational c(3, 2);
    c -= Rational(1, 3);
    cout << "TEST -=: the following should be 7 / 6: " << c << endl;
    
    // Test *=
    Rational d(3, 2);
    d *= d;
    cout << "TEST *=: the following should be 9 / 4: " << d << endl;
    
    // Test /=
    Rational e(3, 2);
    e /= Rational(3, 4);
    cout << "TEST /=: the following should be 2 / 1: " << e << endl;
    
    // Test +
    cout << "TEST +: the following should be -38 / 3: " << Rational(7) + Rational(-59, 3) << endl;

    // Test -
    cout << "TEST -: the following should be 257 / 12: " << Rational(7, 4) - Rational(-59, 3) << endl;

    // Test *
    cout << "TEST *: the following should be -1 / 4: " << Rational(1, -6) * Rational(-3, -2) << endl;

    // Test /   
    cout << "TEST /: the following should be 1 / 9: " << Rational(1, -6) / Rational(-3, 2) << endl;


    // Test ==
    bool condition = Rational(18, 30) == Rational(21, 35) && !(Rational(18, 30) == Rational(18, 20));
    if (condition) {
        cout << "TEST ==: passed" << endl;
    } else {
        cout << "TEST ==: failed" << endl;
    }

    // Test !=
    bool condition2 = !(Rational(1, 2) != Rational(-1, -2)) && (Rational(5, 7) != Rational(5, 9));
    if (condition2) {
        cout << "TEST !=: passed" << endl;
    } else {
        cout << "TEST !=: failed" << endl;
    }

    // Test <=
    bool condition3 = (Rational(1, 2) <= Rational(-1, -2)) && !(Rational(5, 7) <= Rational(5, 9)); 
    condition3 = condition3 && (Rational(-3) <= Rational(4, 7)) && (Rational(24, 7) <= Rational(14, 4));
    if (condition3) {
        cout << "TEST <=: passed" << endl;
    } else {
        cout << "TEST <=: failed" << endl;
    }
    
    // Test >=
    bool condition4 = (Rational(1, 2) >= Rational(-1, -2)) && (Rational(5, 7) >= Rational(5, 9)); 
    condition4 = condition4 && (Rational(4, 7) >= Rational(-3)) && !(Rational(24, 7) >= Rational(14, 4));
    if (condition4) {
        cout << "TEST >=: passed" << endl;
    } else {
        cout << "TEST >=: failed" << endl;
    }
    
    // Test <
    bool condition5 = !(Rational(1, 2) < Rational(-1, -2)) && !(Rational(5, 7) < Rational(5, 9)); 
    condition5 = condition5 && (Rational(-3) < Rational(4, 7)) && (Rational(24, 7) < Rational(14, 4));
    if (condition5) {
        cout << "TEST <: passed" << endl;
    } else {
        cout << "TEST <: failed" << endl;
    }

    // Test >
    bool condition6 = !(Rational(1, 2) > Rational(-1, -2)) && (Rational(5, 7) > Rational(5, 9)); 
    condition6 = condition6 && (Rational(4, 7) > Rational(-3)) && !(Rational(24, 7) > Rational(14, 4));
    if (condition6) {
        cout << "TEST >: passed" << endl;
    } else {
        cout << "TEST >: failed" << endl;
    }

    // Test >>
    cout << "TEST >>: Enter 143 / -91: ";
    Rational input;
    cin >> input;
    input.reduce();
    cout << "This should print out -11 / 7: " << input;
}
