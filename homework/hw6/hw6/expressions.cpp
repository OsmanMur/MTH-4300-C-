////////////////////////////////////////////////////////////////////////////////
// expressions.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "rational.h"

using std::cout; using std::cin; using std::endl; using std::string;


int main() {

    Rational expr1 = Rational(1) - Rational(1,2) + Rational(1,3) - Rational(1,4) + Rational(1,5) - Rational(1,6) + Rational(1,7);
    cout << "Expression 1: " << expr1 << endl;

    Rational expr2 = Rational(1,1*1*1) + Rational(1,2*2*2) + Rational(1,3*3*3) + Rational(1,4*4*4) + Rational(1,5*5*5);
    cout << "Expression 2: " << expr2 << endl;

    Rational expr3 = Rational(1) + Rational(1,2) + Rational(1,3) + Rational(1,4) + Rational(1,5) + Rational(1,6) + Rational(1,7) + Rational(1,8);
    cout << "Expression 3: " << expr3 << endl;

    return 0;
}