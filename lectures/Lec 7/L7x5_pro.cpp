////////////////////////////////////////////////////////////////////////////////
// Pro
// A string of letters is "pronounceable" if there are no more than two
// consonants in a row.  How many pronounceable words of length n are there?
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int NUM_CONS = 21;
int NUM_VOWELS = 5;

/* Counts the number of pronounceable strings which start with AT MOST `max_leading_cons` consonants.
*/
long long helper(long long length, long long max_leading_cons) {
	if (max_leading_cons < 0) {  
		return 0; // Impossible to have negative leading consonants
	} else if (length == 0) {
		return 1; // The empty string
	}
	long long num_head_vowel = NUM_VOWELS * helper(length - 1, 2);
	long long num_head_cons = NUM_CONS * helper(length - 1, max_leading_cons - 1);
	return num_head_vowel + num_head_cons;
}

/* Counts the number of pronounceable strings of length `n`
*/
long long num_pro(int n) {
	// Every pronounceable string starts with at most 2 consonants.
	return helper(n, 2);   
}

int main() {	
	cout << num_pro(5) << endl;
	return 0;
}