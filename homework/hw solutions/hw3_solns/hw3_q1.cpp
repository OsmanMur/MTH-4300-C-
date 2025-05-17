////////////////////////////////////////////////////////////////////////////////
// hw3_q1.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION
////////////////////////////////////////////////////////////////////////////////

/* 
a. The addresses next to A, D and E will all be the same; all others will be 
   different from one another.  See stack illustration in p1.jpg.  The illustration
   gives a depiction of the stack from right before the function f() returns.
b. 12345 8 32   // From f()
   12345 12345 35 // From main()
*/

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

int f(int & p1, int p2) {
	int local = p1 * 4;
	p1 = 12345;
	cout << "A: " << &p1 << endl;
	cout << "B: " << &p2 << endl;
	cout << "C: " << &local << endl;
	
	cout << p1 << ' ' << p2 << ' ' << local << endl;
	return local;
}

int main() {
	int x = 8;
	int &y = x;
	int z = y;
	
	z = f(x, z) + 3;	
	
	cout << "D: " << &x << endl;
	cout << "E: " << &y << endl;
	cout << "F: " << &z << endl;	
	
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}
