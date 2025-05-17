////////////////////////////////////////////////////////////////////////////////
// Array
// A program illustrating functions with array parameters.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

/* Returns the sum of the entries in array x, with length len
   @param x       An array to be summed
   @param len     The length of the array
   @precondition  The length of `x` is equal to `len`
   @returns       The sum of entries in x
*/
double sum(const double x[], int len) {
	cout << "x = " << x << " and &len = " << &len << endl;
	double rs = 0;
	for (int idx = 0; idx < len; ++idx) {
		rs += x[idx];
	}
	//x[0] = 7;
	return rs;
}

//void fn (int x, int y[]) //input array and output for copy


int main() {
	double arr[7] = {1, 2, 3.4, 5.6, 1, 1, 1};
	int length = 7;
	cout << "To observe that arrays are passed by reference, observe the addresses below.";
	cout << "arr = " << arr << " and &length = " << &length << endl;
	
	cout << sum(arr, length) << endl;
	cout << arr[0];
	return 0;
}
