// Problem 14
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


/* @precondition    n >= 1
*/
int num_p_factors(int n) {
    if (n == 1) {
        return 0;
    }
    for (int factor = 2; factor < n; ++factor) {
        if (n % factor == 0) {
            return 1 + num_p_factors(n / factor); // The first factor of n encountered will be a prime factor.
        }
    }
    return 1;
}

int main() {
    cout << num_p_factors(7) << endl;  // 7
    cout << num_p_factors(15) << endl;  // 3*5
    cout << num_p_factors(24) << endl;  // 2*2*2*3
    cout << num_p_factors(143) << endl; // 11*13
    cout << num_p_factors(168) << endl; // 2*2*2*3*7
}
