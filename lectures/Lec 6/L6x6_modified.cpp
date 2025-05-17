////////////////////////////////////////////////////////////////////////////////
// Modified
// Recursive Fibonacci sequence
// With a slightly elongated fib() function, the better to visualize at 
// https://pythontutor.com/cpp.html
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

// Returns the nth term of the Fibonacci sequence
// Preconditions: n >= 1
int fib(int n) {
	if (n <= 2) {
		return 1;
	}
	int a = fib(n-1);
	int b = fib(n-2);
	return a + b;
}


int main() {	
	cout << fib(7);
	return 0;
}
