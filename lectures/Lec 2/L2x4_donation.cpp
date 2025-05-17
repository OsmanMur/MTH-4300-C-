////////////////////////////////////////////////////////////////////////////////
// Donation
// Ask for donations, until the funding goal of 10000 is met.
// Then, print out the total amount raised.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
	int sum = 0; // necessary for incrementation
   
	while (sum<10000){
		cout << "We have not met the goal yet, enter an amount to donate: "; 
		int donation;

		cin >> donation;
		sum += donation;
		
	}

	cout << "Total amount raised: " << sum << endl;
	return 0;
}