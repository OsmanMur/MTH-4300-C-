////////////////////////////////////////////////////////////////////////////////
// Func
// The basic syntax of functions
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

// Write a function that receives two strings as arguments.
// It returns a bool, true if the two arguments have the same size.

/* Returns whether or not the two strings are the same size
   @param x   A string being compared
   @param y   A string being compared
   @return    Whether the two arguments have the same length
*/
bool same_size (string x, string y){
	 return (x.size() == y.size());
}

int main() {
	string a, b;
	cout << "Enter two words: ";
	cin >> a >> b; // remember cin is sepreated by spaces
	
	if (same_size(a, b)) {
		cout << "They have the same length.";
	} else {
		cout << "They have different lengths.";
	}
	
	return 0;
}