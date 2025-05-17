////////////////////////////////////////////////////////////////////////////////
// Average
// Create a program which does the following:
// - Declares int variables x and y
// - Asks the user to enter values for these variables, and write code which 
//   accepts those values
// - Prints out "The average is:" with the properly-calculated average of 
//   x and y on the next line, using a SINGLE cout statement.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int main() {
    int x, y;
	std::cout << "Enter x: ";
	std::cin >> x;
	
	std::cout << "Enter y: ";
	std::cin >> y;
	
	double avg = (x + y)/2.0; // Without the 2.0, integer division takes place.
    std::cout << "The average is: " << avg << std::endl; 
	return 0;
}