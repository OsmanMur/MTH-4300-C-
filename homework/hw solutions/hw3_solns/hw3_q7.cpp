////////////////////////////////////////////////////////////////////////////////
// hw3_q7.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Returns x^n, recursively
   @param x          Base
   @param n          Exponent
   @precondition     x > 0 
   @returns          x^n
*/
double power(double x, int n) {
    if (n == 0) {
        return 1;
    } else if (n < 0) {
        return 1/power(x, -n);
    } else {
        return x * power(x, n-1);
    }
}

int main() {
    cout << power(5, 3) << endl;
    cout << power(4, 0) << endl;
    cout << power(10, -2) << endl;
}