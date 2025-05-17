////////////////////////////////////////////////////////////////////////////////
// Swap
// A swap program illustrating reference variables.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

// No reference parameters yet!
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int big, small;
	cout << "Enter two numbers: ";
	cin >> big >> small;
	if (big <= small) {
		swap(big, small);
	}
	cout << "big is " << big << " & small is " << small;
	return 0;
}
//int is 4 bytes
//double is 8 bytes