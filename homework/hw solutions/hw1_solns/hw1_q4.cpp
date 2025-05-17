////////////////////////////////////////////////////////////////////////////////
// hw1_q4.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

// SEE BELOW FOR TWO MORE SOLUTIONS!
int main() {
    cout << "Enter two positive integers: ";
    int x, y;
    cin >> x >> y;
    int gcd = 1;
    for(int i = 1; i <= x; ++i) {
        if (x % i == 0 && y % i == 0){
            gcd = i;
        }
    }
    cout << gcd;
    return 0;
}

// ALTERNATIVE 1: EUCLIDEAN ALGORITHM, NON-RECURSIVE

/*
int main() {
    cout << "Enter two positive integers: ";
    int x, y;
    cin >> x >> y;
    while(y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    cout << x;
    return 0;
}
*/


// ALTERNATIVE 2: EUCLIDEAN ALGORITHM, RECURSIVE

/*
// Returns the greatest common divisor of arguments x and y 
   (computed using the recursive version of the Euclidean algorithm)
   @param x        integer
   @param y        integer
   @precondition   x, y >= 0
   @returns        GCD(x,y)
//
int euc_rec_gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return euc_rec_gcd(y, x % y);
}

int main() {
    cout << "Enter two positive integers: ";
    int x, y;
    cin >> x >> y;
    cout << euc_rec_gcd(x, y);
    return 0;
}
*/