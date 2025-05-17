////////////////////////////////////////////////////////////////////////////////
// hw3_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Copies elements from one array to another
   @param given   A constant integer array that serves as the source
   @param copy    An integer array that will store the copied values
   @param len     The number of elements to copy
   @precondition   given and copy have at least len elements
*/

// WRITE YOUR FUNCTION `copy()` HERE.
void copy(const int given[], int copy[], int len){
	for(int i = 0; i < len; ++i) {
		copy[i] = given[i];
	}
}


int main() {
	int arr[10] = {4, 7, 3, 0, -1, 2, 8, 5, 1, 2};
	int arr2[10];	
	//arr2 = arr; NOPE!

    //
    // WRITE YOUR CALL TO THE FUNCTION `copy()` HERE.
    //
	copy(arr, arr2, 10);

	for(int i = 0; i < 10; ++i) { // Check that it works!
		cout << arr2[i] << " ";
	}
}
