////////////////////////////////////////////////////////////////////////////////
// Bignum
// Some peculiarities of the int type, including integer overflow
// Also, we introduce the long long type.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int main() {
    int big_fellow = 2'147'483'647;  // The single quote in the integer literal act like commas
    int big_plus_5 = big_fellow + 5;
    
    // What will print out?  Who knows, but probably a negative number.
    std::cout << "big_plus_5 is " << big_plus_5  << std::endl;

    long long another_big = 3'000'000'000'000;                             // These should behave reasonably, though.
    std::cout << "another_big + 1 is " << another_big + 1 << std::endl;    //

	return 0;
}