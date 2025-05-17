////////////////////////////////////////////////////////////////////////////////
// Char
// The char data type
// Note that chars are integer types: each char value corresponds to an integer.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int main() {
    char x = 'a', y = '\n', z = '\'';

    std::cout << x << y << z << std::endl;

    std::cout << "Watch the type conversions: " << std::endl;
    // First example:
    std::cout << x + 5 << std::endl;    

    // Second example:
    char newchar = x + 5;       //intializing it as an char makes it back to letter        
    std::cout << newchar << std::endl;

	return 0;
}