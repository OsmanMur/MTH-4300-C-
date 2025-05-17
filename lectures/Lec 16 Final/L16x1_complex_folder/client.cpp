////////////////////////////////////////////////////////////////////////////////
// client
// Client code of the Complex class.
////////////////////////////////////////////////////////////////////////////////
#include "complex.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main () {
	Complex z1(4, 5); 
	Complex z2(3);    
	Complex z3;

	cout << "Enter a value for z3: ";
    cin >> z3;
    cout << z1 << " + " << z3 << " = " << z1 + z3 << endl;
	if (z1 == z3) {
		cout << z1 << " is equal to " << z3 << endl;
	} else {
		cout << z1 << " is not equal to " << z3 << endl;
	}

	return 0;   
}