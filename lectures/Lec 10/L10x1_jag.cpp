////////////////////////////////////////////////////////////////////////////////
// Jag
// Creating a jagged 2D-array representing:
// 1 2 3
// 8 6 7 5 3
// 0 9 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () { 
	// First, create a pointer for the entire object:
	int **jagged; 

	// Remember:  an int* generally is a pointer to an array of ints, so it stands to reason that
	//            an int** generally is a pointer to an array of int*s.
	jagged = new int*[3];
	
	// We create an array of three int*'s -- these will be the addresses of the 3 rows.
	jagged[0] = new int[3]; // Row 1
	jagged[1] = new int[5]; // Row 2
	jagged[2] = new int[2]; // Row 3

	// If we were to print out, say, jagged[0], we'd see the address of the array allocated by `new int[3];`
	cout << jagged[0] << endl;

	// Now, we fill out.  Remember, jagged[0][0] is the same as *(jagged[0] + 0) 
	// -- read the address in jagged[0], add 0 to that address, and go to the address.
	jagged[0][0] = 1;

	// And the rest....
	jagged[0][1] = 2; jagged[0][2] = 3;
	jagged[1][0] = 8; jagged[1][1] = 6; jagged[1][2] = 7; jagged[1][3] = 5; jagged[1][4] = 3;
	jagged[2][0] = 0; jagged[2][1] = 9;

	//ORDER MATTERS
	//delete[]jagged; --> deleting this will kill the reference to the memory storing the heap.
	delete[]jagged[0];
	delete[]jagged[1];
	delete[]jagged[2];

	delete[]jagged;
	
	// Check out pythontutor.com to visualize!  I also recommend viewing addresses as the code executes.	
    return 0;   

}
