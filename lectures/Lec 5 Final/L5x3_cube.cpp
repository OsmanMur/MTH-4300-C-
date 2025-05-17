////////////////////////////////////////////////////////////////////////////////
// Cube
// Another program to illustrate the stack.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int square(int x) {
	cout << "&x: " << &x << endl;
	return x*x;
}

int cube(int x) {
	int sq = square(x);
	cout << "&x: " << &x << " &sq: " << &sq << endl;
	return sq * x;
}

int main() {
	int z = 2;
	int w = cube(z);
	cout << "&z: " << &z << " &w: " << &w << endl;
	return 0;
}
