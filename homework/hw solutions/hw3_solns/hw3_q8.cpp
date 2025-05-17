////////////////////////////////////////////////////////////////////////////////
// hw3_q8.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Returns the greatest integer k such that 2^k <= n
   @param n          Integer
   @precondition     n >= 1
   @returns          The greatest integer k which is <= log_2 n
*/
int log_floor(int n) {
    if (n == 1) {
        return 0;
    } else {
        return 1 + log_floor(n/2);
    }
}

int main() {
    cout << log_floor(1) << endl;
    cout << log_floor(2) << endl;
    cout << log_floor(31) << endl;
    cout << log_floor(32) << endl;
    cout << log_floor(33) << endl;
}