////////////////////////////////////////////////////////////////////////////////
// Fact
// A recursive factorial.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns n!, computed recursively
   @param n        integer whose factorial is computed
   @precondition   n >= 0
   @returns        n factorial
*/
int fact(int n) {
	if (n <= 1) { //base case 
		return 1;
	} 
	return n * fact(n-1); // recursive calls need to move towards base case.
}


int main() {	
	int x = fact(3);
	cout << x << endl; // Replace 3 with a greater value for a more interesting output.
	return 0;
}

//When you exceed the available space of memory its called a 'stack overflow'