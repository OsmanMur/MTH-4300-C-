////////////////////////////////////////////////////////////////////////////////
// Incr
// Looking at the difference between prefix and postfix increment
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int p = 20, q = 20;

	cout << "p++ is " << p++ << endl;
	cout << "++q is " << ++q << endl;
	cout << "p is now " << p << " and q is now " << q << endl;

	
	int x = 1;
	// The following two lines are undefined, since there is no guarantee 
	// whether x++ or --x takes place first in either line.  
	// Don't write things like this.
	int y = (x++ + --x);
	int z = (--x + x++);
	cout << "Apparently y = " << y << " and z = " << z << endl;
	cout << "(But y and z could easily be reversed)" << endl;
	return 0;
}