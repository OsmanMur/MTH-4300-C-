////////////////////////////////////////////////////////////////////////////////
// hw3_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Writes contents of `x` into `y`
   @param x        Array writing from
   @param y        Array copied to 
   @param length   Size of `x`
   @precondition   `y` is at least as long as `x`.
*/
void copy(int x[], int y[], int length) {
    for (int idx = 0; idx <= length - 1; ++idx) {
        y[idx] = x[idx];
    }
}

int main() {
	int arr[10] = {4, 7, 3, 0, -1, 2, 8, 5, 1, 2};
	int arr2[10];	
	//arr2 = arr; NOPE!
	copy(arr, arr2, 10);

	for(int i = 0; i < 10; ++i) { // Check
		cout << arr2[i] << " ";
	}
}
