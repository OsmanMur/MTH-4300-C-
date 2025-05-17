////////////////////////////////////////////////////////////////////////////////
// Fib
// Recursive Fibonacci sequence
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the nth Fibonacci number
   @param n       Term number
   @precondition  n >= 1
   @return        The nth Fibonacci number
*/
int fib(int n) {
	if (n <= 2) {
		return 1;
	}
	return fib(n-1) + fib(n-2);
}


int main() {	
	cout << fib(7);
	return 0;
}
