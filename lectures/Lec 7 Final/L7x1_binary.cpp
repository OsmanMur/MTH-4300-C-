////////////////////////////////////////////////////////////////////////////////
// Binary
// Binary Search of sorted array, implemented with a recursive function.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


/* Searches for a value in a sorted array.
   @param arr       An array containing values to be sorted
   @param value     Value being searched for
   @param left_bd   Lower index of the search range
   @param right_bd  Upper index of the search range
   @precondition    `arr` is sorted, 
                    `left_bd` and `right_bd` either satisfy `left_bd` > `right_bd`, 
					or are both in the interval [ 0 , L-1 ] where L is the length of `arr` 
   @returns         true if `value` is equal to an entry of `arr` with index >= `left_bd` and <= `right_bd`
*/
bool bin_search(string arr[], string value, int left_bd, int right_bd){
	if (left_bd > right_bd) {
		return false;
	}
	int midway = (left_bd + right_bd) / 2;  // This is an integer!

	if (value < arr[midway]) {
		return bin_search(arr, value, left_bd, midway - 1);
	} else if (value > arr[midway]) {
		return bin_search(arr, value, midway + 1, right_bd);
	} else {
		return true;
	}
}


int main() {
	string names[] = {"Alice", "Bob", "Carol", "David", "Evan", "Frank", "George", "Howard", "Isabel"};
	cout << bin_search(names, "Carol", 0, 8) << endl; // Prints 1, for true
	cout << bin_search(names, "Charles", 0, 8) << endl; // Prints 0, for false
}