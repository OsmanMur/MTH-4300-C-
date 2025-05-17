////////////////////////////////////////////////////////////////////////////////
// Prod
// A recursive product of array function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the product of the entries between index `i` and index `j` (inclusive) in array `x`
   @param x       An array containing entries to be multiplied
   @param i		  The lower index of the range to be multiplied
   @param j       The upper index of the range to be multiplied
   @precondition  0 <= i <= j < length(x)
   @return        The product of entries between index `i` and index `j`
*/
int product(const int x[], int i, int j) {
	if (i == j) {
		return x[i];
	}
	return x[i] * product(x, i + 1, j);
}


int main() {	
	int arr[6] = {3, 1, 2, 10, 5, 8};
	
	cout << product(arr, 0, 5);
	
	return 0;
}
