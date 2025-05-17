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
    int x, y ;

    std::cout << "Enter an integer for x: "; 
    std::cin >> x;

    std::cout << "Enter an integer for y: "; 
    std::cin >> y;

    double avg = (x+y)/2.0; // NOTICE that it not a decimal even thought we made it a double b/c its an int divided by int(2)! FIXED if we divided by 2.0

    std::cout << "The average is: " << avg << std::endl;
        
    return 0;

}