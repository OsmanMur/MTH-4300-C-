////////////////////////////////////////////////////////////////////////////////
// Void
// A void function
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Prints a greeting
   @param n   Name inserted into greeting
*/
void greeting(string n){
	cout << "Hello, " << n << ", nice to meet you.\n";
}

int main() {
	string name;
	cout << "Enter a name: ";
	cin >> name;
	greeting(name);
	
	cout << "Enter another name: ";
	cin >> name;
	greeting(name);
	
	return 0;
}