////////////////////////////////////////////////////////////////////////////////
// Ref
// An introduction to reference variables.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	double num = 1.23;
	double num2 = num;
	double &my_ref = num; // Reference variable -- needs to be bound to an existing variable at initialization.

	cout << "Values of num, my_ref: " << num << " " << my_ref << endl;
	cout << "Addresses of num, my_ref: " << &num << " " << &my_ref << endl;
	
	num += 10;
	my_ref += 200;
	num2 += 7;
	
	cout << "New values of num, num2, my_ref: " << num << " " << num2 << " " << my_ref << endl;
	
	// THE FOLLOWING ARE ILLEGAL:
	&my_ref = num2;  // You can't "reseat" a reference.
	double &new_ref; // What is new_ref referring to?
	double &const_ref = 10.0; // Must refer to a VARIABLE.
	
	return 0;
}