////////////////////////////////////////////////////////////////////////////////
// Assign
// Exploring chained assignments
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int p, q = 20;

	p = q += 30;
	cout << "(p+=q=10) returns " << (p += q = 10) << endl;
	cout << "p = " << p << " and q = " << q << endl;
	
	return 0;
}