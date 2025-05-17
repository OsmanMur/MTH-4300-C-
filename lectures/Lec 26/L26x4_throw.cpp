////////////////////////////////////////////////////////////////////////////////
// Throw
// Generating our own exceptions.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Rational {
private:
    long long num, den;
public:
    Rational(long long n = 0, long long d = 1): num{n}, den{d} {
        if (d == 0) {
            throw "Division by zero.  Also, this isn't an ideal use of throw";
        }
    }
};



int main() {
    Rational x(5, 8);
    Rational y(2, 0);
}