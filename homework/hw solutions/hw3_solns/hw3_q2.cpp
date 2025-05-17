////////////////////////////////////////////////////////////////////////////////
// hw3_q2.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

/*
doubles are typically 8 bytes. Therefore,
0x34f9dff8b0 should be followed by
0x34f9dff8b8
0x34f9dff8c0
0x34f9dff8c8
0x34f9dff8b0   <--- x is the address of the first element
*/

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	double x[4];	
	cout << &(x[0]) << endl;
	cout << &(x[1]) << endl;
	cout << &(x[2]) << endl;
	cout << &(x[3]) << endl;	
	cout << x << endl;	
}