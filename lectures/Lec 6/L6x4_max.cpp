////////////////////////////////////////////////////////////////////////////////
// Max
// A recursive maximum of array function.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the max of the entries between index `i` and index `j` in array `x`
   @param x       An array containing entries to be examined
   @param i		  The lower index of the range to be examined
   @param j       The upper index of the range to be examined
   @precondition  0 <= i <= j < length(x)
   @returns       The max value of entries between index `i` and index `j`
*/

// DON'T USE THE BUILT IN MAX FUNCTION
int range_max(int x[], int i, int j) {
	
if (i == j){
   return x[i];
}

int temp = range_max(x,i+1,j);
if (x[i]  > temp){
   return x[i];
} 
return temp;

	
}


int main() {	
	int arr[6] = {3, 1, 2, 10, 5, 8};
	
	cout << range_max(arr, 0, 5);
	
	return 0;
}
