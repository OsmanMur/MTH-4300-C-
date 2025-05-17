////////////////////////////////////////////////////////////////////////////////
// Input
// `std::getline()` versus `cin >>`
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>  

using std::cout; using std::cin; using std::endl; using std::string;  

int main() {
    string in1, in2;
    
    // `getline()`
    cout << "Enter some input: ";
    std::getline(cin, in1); // Takes the whole line
    cout << "in1 is: " << in1 << endl;
	
    // `cin >>`
    cout << "Enter more input: ";
    cin >> in2; // Takes one "word"
	cout << "in2 is: " << in2 << endl;

	return 0;
}