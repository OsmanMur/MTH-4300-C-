////////////////////////////////////////////////////////////////////////////////
// Stdstr
// A little bit about strings
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>  

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string x = "Hello";  // If you mouse over the string literal, you will see its type:
                         // an array of characters of size 6.

    string y = x + " people";   // Concatenation: works because x is a std::string
    cout << "The length of " << y << " is " << y.size() << endl;

    // When you subtract one from the length, something funny happens.
    string empty = "";
    std::cout << "(Length of empty) - 1 = " << empty.size() - 1 << std::endl; 

    // Notice: we replace y[0] with a CHAR, not a string.
    y[0] = 'J'; 
    std::cout << "NOW, y is: " << y << std::endl;

    std::string in1, in2;
    std::cout << "Enter some input: ";
    getline(std::cin, in1); // Takes the whole line
    std::cout << "in1 is: " << in1 << std::endl;
	
    std::cout << "Enter more input: ";
    std::cin >> in2; // Takes one "word"
	std::cout << "in2 is: " << in2 << std::endl;
	return 0;
}