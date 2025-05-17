////////////////////////////////////////////////////////////////////////////////
// hw3_q7.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Computes the power of a number raised to an exponent 
   @param x   A double representing the base
   @param n   An integer representing the exponent
   @precondition   x is a valid real number, and n is an integer
   Returns x raised to the power of n 
*/

// WRITE YOUR RECURSIVE FUNCTION `power()` HERE.
double power(double x, int n){
    if (n == 0) {
        return 1; // Base case x^0 = 1
    }
    else if (n < 0){
        return 1 / power(x, -(n)); // accounts for negative integer exponents by turning them positve
    }

    return x * power(x, n - 1); 
}

int main() {
    cout << power(5, 3) << endl;
    cout << power(4, 0) << endl;
    cout << power(10, -2) << endl;
}