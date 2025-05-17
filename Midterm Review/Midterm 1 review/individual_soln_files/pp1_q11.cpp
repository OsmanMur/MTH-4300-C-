// Problem 11

/*
Assuming 4-byte ints:
0x505298 0x505290 14 30

NOTE: IF YOU GOT THAT THE LAST TWO NUMBERS WERE BOTH 14 INSTEAD OF 14 30, YOU PROBABLY
SOLVED THE OLD VERSION OF THE PROBLEM.  SEE x[6] BELOW.
*/

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int x[6] = {10, 15, 20, 25, 30, 35};
	cout << x + 3 << " " << &(x[1]) << " " << *x + 4 << " " << *(x + 4);
}