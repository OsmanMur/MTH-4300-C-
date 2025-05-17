////////////////////////////////////////////////////////////////////////////////
// hw3_q8.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Computes the floor of the base-2 logarithm of n
   @param n   An integer representing the input value
   @precondition   n > 0
   Returns the largest integer k such that 2^k <= n
*/

// WRITE YOUR RECURSIVE FUNCTION `log_floor()` HERE.
int log_floor(int n){
    if (n == 1) { // Base case log_floor(1) = 0 since 2^0 = 1
        return 0; 
    }
    return log_floor(n / 2) + 1; // Recursively divide by 2 and add 1 for count of k 
}

int main() {
    cout << log_floor(1) << endl;
    cout << log_floor(2) << endl;
    cout << log_floor(31) << endl;
    cout << log_floor(32) << endl;
    cout << log_floor(33) << endl;
   
}