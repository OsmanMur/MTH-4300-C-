////////////////////////////////////////////////////////////////////////////////
// Twod
// Introduction to 2D arrays
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
	int two_d[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}};
	
	for(int row_idx = 0; row_idx < 2; ++row_idx) {
		for(int col_idx = 0; col_idx < 4; ++col_idx) {
			cout << two_d[row_idx][col_idx] << " ";
		}
		cout << endl;
	}
	
	// When declaring 2D arrays with initializer lists, 
	// the FIRST DIMENSION ONLY can be omitted.
	int new2d[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
	
	return 0;
}