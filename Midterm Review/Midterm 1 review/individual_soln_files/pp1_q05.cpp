// Problem 5 

/*
a. A void function should not have a return, so the line `return b;` generates a compiler error.
b. The print out is:
2)5 20
1)25 45
3)25 20 
*/

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

void my_f(int &b, int c) {
	b += c;
	c += b;
	cout << "1)" << b << " " << c << endl;
	//return b;
}

int main() {
	int a = 5, b = 20;
	cout << "2)" << a << " " << b << endl;
	my_f(a, b);
	cout << "3)" << a << " " << b << endl;
}