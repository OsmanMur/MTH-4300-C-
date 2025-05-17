////////////////////////////////////////////////////////////////////////////////
// Donation
// Ask for donations, until the funding goal of 10000 is met.
// Then, print out the total amount raised.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
    int total = 0;

	while (total < 10000) {
		cout << "Enter an amount to donate: ";
		int individual_donation; // Since the variable individual_donation is only used within this loop,
		                         // it can be declared withint the loop.
		cin >> individual_donation;
		total += individual_donation;
	}
	cout << "Total amount raised: " << total << endl;
	return 0;
}