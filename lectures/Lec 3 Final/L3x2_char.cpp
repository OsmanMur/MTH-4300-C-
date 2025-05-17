////////////////////////////////////////////////////////////////////////////////
// Char
// The char data type
// Note that chars are integer types: each char value corresponds to an integer.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    char x = 'a', y = '\n', z = '\'';

    cout << x << y << z << endl;

    cout << "Watch the type conversions: " << endl;
    // First example:
    cout << x + 5 << endl;          // x's value gets converted to 97, so that it can be added to 5
                                    // char + int gives an int.
    
    // Second example:
    char newchar = x + 5;           // Since newchar is a char, the righthand value of 102 gets 
                                    // converted to the char 'f'.
    cout << newchar << endl;

	return 0;
}