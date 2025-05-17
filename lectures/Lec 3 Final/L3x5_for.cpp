////////////////////////////////////////////////////////////////////////////////
// For
// Anatomy of a for loop.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int x = 0;
	
	// Initializer;  test;  increment (++i is the same as i+=1)
	for(int i = 1; i <= 3; ++i){
		x += i;
		cout << x << " " << i << endl;
	}
	cout << x << endl << endl;
	
	
	// A WARNING about looping through strings by index
	string y = "abcd";
	
	// If you were to change `y` to be an empty string, this will be trouble, since
	// `y.size()` is an UNSIGNED int, and when you subtract 1 from an unsigned int, 
	// you typically get a huge positive number instead of -1
	for (int i = 0; i <= y.size() - 1; ++i) {   
		cout << y[i] << endl;
	}
	// USE 		`i < y.size()`		INSTEAD OF 		`i <= y.size() - 1`

    

	// An alternative way to loop through a string, which has been part of C++ since C++11:
    for (char let: y){ 
		cout << let << endl;
	}
	// let represents an individual letter in y




	
	return 0;
}