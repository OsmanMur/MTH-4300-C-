////////////////////////////////////////////////////////////////////////////////
// Tri
// Creating a dynamic jagged 2D-array.  Using loops, of course.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
	
	int ** jag;
	jag = new int*[3];
	jag[0] = new int[3];
	jag[1] = new int[5];
	jag[2] = new int[2];

	jag[0][0] = 1; // jag[0] --> (jag[0]+0)				similar to:[2]-->*(x+2)
	jag[0][1] = 2;
	jag[0][2] = 3;
	
	return 0;
}
