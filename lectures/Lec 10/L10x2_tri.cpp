////////////////////////////////////////////////////////////////////////////////
// Tri
// Creating a dynamic jagged 2D-array.  Using loops, of course.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
    int **triangle; 
	// FIRST, CREATE THE THING!
    triangle  = new int* [5];

	for (int i = 0; i < 5; ++i){
		triangle[i] = new int [i+1];
	}
	
	// NOW, FILL OUT!
	int counter = 0;

	for (int i = 0; i < 5; ++i){
		for(int j = 0; j<=i; ++j){
		triangle[i][j] = counter;
		++counter;
		}
	}


	for (int i = 0; i < 5; ++i){
		delete triangle[i];
	}

	delete[] triangle;

	// Check out pythontutor.com to visualize!  I also recommend viewing addresses as the code executes.	
    return 0;   
}
