////////////////////////////////////////////////////////////////////////////////
// For
// Anatomy of a for loop.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int x = 0;
	int i;
	
	// Initializer;  test;  increment (++i is the same as i+=1)
	for(i = 1; i <= 3; ++i){ //first the intializer, then the test, then body and lastly the increment 
		x += i; // i is intialized in the scope of the for loop so out of the loop it doesnt exist
		cout << x << " " << i << endl;
	}
	cout << x << i << endl << endl;
	
	
	// A WARNING about looping through strings by index
	string y = "abcd";
	
	// If you were to change `y` to be an empty string, this will be trouble, since
	// `y.size()` is an UNSIGNED int, and when you subtract 1 from an unsigned int, 
	// you typically get a huge positive number instead of -1
	for (int i = 0; i <= y.size(); ++i) {   
		cout << y[i] << endl;
	}

	for ( char x:y ){
		cout << x << endl;

	}
	// USE 		`i < y.size()`		INSTEAD OF 		`i <= y.size() - 1`
	
	return 0;
}