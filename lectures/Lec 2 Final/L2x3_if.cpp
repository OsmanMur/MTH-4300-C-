////////////////////////////////////////////////////////////////////////////////
// If
// if, else, bool values.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

//
// This is a shortcut we will start using. 
//
using std::cout; using std::cin; using std::endl;

int main() {
    int x, y;
    cout << "Enter two positive ints: ";
    cin >> x;
    cin >> y;

    if (x % 2 == 0 && y % 2 == 0){
        cout << "Two ";
        cout << "Evens!" << endl;
    } 
    else if (x % 2 == 0 || y % 2 == 0) {
        cout << "One ";
        cout << "Even!" << endl;
    } 
    else {
        cout << "Zero ";
        cout << "Evens!" << endl;
    }

	// In an if statement, any non-zero value will be interpreted as true.
	if (x) {
		cout << "See, the value of x was treated as a true value!" << endl;
	}

	return 0;
}