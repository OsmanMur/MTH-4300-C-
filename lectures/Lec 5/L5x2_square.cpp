////////////////////////////////////////////////////////////////////////////////
// Square
// A program to illustrate the stack.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int square(int x) {
	x = x*x;
	cout << "&x: " << &x << endl;
	return x;
}

int main() {
	int z = 3;
	int w = square(z);
	cout << "&z: " << &z << " &w: " << &w << endl;
	cout << "w is: " << w;
	return 0;
}