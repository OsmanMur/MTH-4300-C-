////////////////////////////////////////////////////////////////////////////////
// Tri
// Creating a dynamic jagged 2D-array.  Using loops, of course.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
	// PHASE 1: ALLOCATE
    int **triangle; 	// Think of this (but don't write it) as (int*) *triangle.  
						// In other words, triangle is a pointer to an int*   
	
	triangle = new int*[5];   	// new int*[5] returns the ADDRESS OF THE FIRST ENTRY
								// of an array of five address-of-ints
	
	for(int i = 0; i < 5; ++i) {
		triangle[i] = new int[i+1];
	}
	// Check out pythontutor.com to visualize!  I also recommend viewing addresses as the code executes.	


	// PHASE 2: FILL OUT
	int entry = 0;
	for(int row = 0; row < 5; ++row) {
		for(int col = 0; col <= row; ++col) {
			triangle[row][col] = entry;
			++entry;
		}
	}

	// PHASE 3: DEALLOCATE
	for(int i = 0; i < 5; ++i) { // Deallocate the rows first... 
		delete[] triangle[i];
	}

	delete[] triangle; // ...then the array that holds the pointers to the rows.

	// Check out pythontutor.com to visualize!  I also recommend viewing addresses as the code executes.	
    return 0;   
}
