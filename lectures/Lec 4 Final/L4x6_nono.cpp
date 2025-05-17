////////////////////////////////////////////////////////////////////////////////
// Nono
// Some array operations that are not allowed.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
	int x[5];
	x = {1, 2, 3, 4, 5}; // NO-NO: initializer lists can only be used at declaration time.
	
	int y[3] = {10, 11, 12};
	int z[3];
	
	y[4] = 14; // NO-NO: out-of-bounds assignment -- undefined behavior
	z = y; // NO-NO: you can't copy entire arrays
	cout << y << endl; // Well, this isn't a NO-NO per se, but it doesn't do what you think.
	
	return 0;
}