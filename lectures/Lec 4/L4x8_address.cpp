////////////////////////////////////////////////////////////////////////////////
// Address
// Memory addresses of objects
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	int x = 5, y = 7;
	cout << "Address of x: " << &x << endl;
	cout << "Address of y: " << &y << endl;
	
	y = x;
	cout << "Address of y is still: " << &y << endl; // address does not change the value does but not the 'box'
	
	int z[4] = {100, 200, 300, 400};
	cout << "Addresses of elements of z: ";
	cout << &(z[0]) << " " << &(z[1]) << " " << &(z[2]) << " " << &(z[3]) << endl; 
	
	cout << "\nBy the way, if you print out the name of an array, ";
	cout << "the address of its first element will be displayed ";
	cout << "(except for char arrays)." << endl;
	cout << "Here is z: " << z;	
	
	char ch_arr[] = {'W', 'O', 'R', 'D', '\0'};
	cout << "\nHere is what happens if you cout the name of an array of characters: " << ch_arr << endl;
	cout << "(If there is no '\\0' at the end of the array, there could be chaos!)" << endl;

	return 0;
}