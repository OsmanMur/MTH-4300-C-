////////////////////////////////////////////////////////////////////////////////
// Prod
// A recursive product of array function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the product of the entries between index `i` and index `j` in array `x`
   @param x       An array containing entries to be multiplied
   @param i		  The lower index of the range to be multiplied
   @param j       The upper index of the range to be multiplied
   @precondition  0 <= i <= j < length(x)
   @returns       The product of entries between index `i` and index `j`
*/
int product(int const x[], int i, int j) { // added const cause x doesnt change

   if (i == j){
      return x[i];
   }
   return x[i] * product(x, i+1, j);
	
}


int main() {	
	int arr[6] = {3, 1, 2, 10, 5, 8};
	
   cout << product(arr, 0, 5)<< endl;
   cout << product(arr, 1, 3)<< endl;
   cout << product(arr, 1, 4)<< endl;
	
	return 0;
}
