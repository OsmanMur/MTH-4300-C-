////////////////////////////////////////////////////////////////////////////////
// Forward
// An example of a forward declaration
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;


// A forward declaration of a function...
double sum_of_squares(double, double);


int main() {
	// ...which is called here...
	double val = sum_of_squares(3, 4);

	cout << val << endl;
	return 0;
}


// ...and is finally defined here, below where it is used.
double sum_of_squares(double x, double y) {
	return x*x + y*y;
}