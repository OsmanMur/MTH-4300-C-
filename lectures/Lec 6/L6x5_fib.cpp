////////////////////////////////////////////////////////////////////////////////
// Fib
// Recursive Fibonacci sequence
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the nth Fibonacci number
   @param n       Term number
   @precondition  n >= 1
   @returns       The nth Fibonacci number
*/

int fib(int n) {
	if (n <= 2) {
		return 1;
	}
	return fib(n-1) + fib(n-2); // since 1 call makes two calls there will be an explosiion of calls
}


int main() {	
	cout << fib(80);
	return 0;
}
