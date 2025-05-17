////////////////////////////////////////////////////////////////////////////////
// Array
// Introduction to plain arrays
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int arr1[5];  // An uninitialized array holding 5 ints.
	
	double arr2[] = {1.2, 3.4, 5.6, 7, 8}; // The length is implied by the initializer list.
	
	constexpr int SIZE = 4; // We haven't discussed constexpr yet, but here it ensures that 
						    // the value of SIZE can be computed at compilation time, long
							// before the program ever runs.
	string arr3[SIZE];  
	
	for(int idx = 0; idx < 4; ++idx) {
		cout << "Enter a name: ";
		cin >> arr3[idx];
	}
	
	for(int idx = 0; idx < 4; ++idx) {
		cout << arr3[idx] << endl;
	}
	
	return 0;
}