////////////////////////////////////////////////////////////////////////////////
// Return
// A dangerous function -- it returns a pointer to a local object,
// which cease to exist after the function finishes running.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* An automated "ask and receive" function 
   @returns   A pointer to a string gotten from standard input */
string* get_a_word() {
	string get;
	cout << "Enter a word: ";
	cin >> get;

	string *ret = &get; // address to a local variable meaning as soson as the fucntion returns something that object/address no longer exists.
	return ret;
	// AT THIS POINT, `get` is deallocated.
	// That means that the value of ret will be the address of 
	// a DEALLOCATED variable.  That's a problem.
} 



int main () {
	string *ans_ptr;
	ans_ptr = get_a_word();

	// ans_ptr is pointing to a dead object.
	cout << *ans_ptr << endl; // undefined behavior: since the stack in the function has already completed it no longer has that address.
    
	return 0;   
}

