////////////////////////////////////////////////////////////////////////////////
// client
// Client code of the Complex class.
////////////////////////////////////////////////////////////////////////////////
#include "complex.h"
#include <iostream>
//what does #include mean and do? --> it includes the content of the file specified
//what does #include "complex.h" mean? --> it includes the content of the file complex.h
// when doing the build process how come the linker does not include complex.h? --> because the linker only links the object files, not the header files
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