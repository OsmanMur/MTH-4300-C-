////////////////////////////////////////////////////////////////////////////////
// Variables
// Declaring variables, with three data types.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

int main() {
	int x = 5, y = 7;    // Declaring and initializing two int variables
	double z = 2.718;    // Declaring a double ("decimal") variable.
	std::string message = "Here is a terrible approximation to e: ";   // A string variable
	
	std::cout << x << y << " " << x + y << std::endl;
	std::cout << message << z << std::endl;
	return 0;
}