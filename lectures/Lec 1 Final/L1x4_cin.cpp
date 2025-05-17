////////////////////////////////////////////////////////////////////////////////
// Cin
// This gives a basic intro to console input using cin.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int main() {
	std::cout << "Enter a number: ";
	
	double input_val;
	std::cin >> input_val;
	
	std::cout << "Here's your number plus one: " << input_val + 1 << std::endl;
	
	return 0;
}