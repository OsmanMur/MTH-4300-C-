// Problem 17 

/*
a. 98 78 98 78
b. The value of new_ptr gets returned from the function, and stored to q.  
new_ptr contains the address of the local variable val_arg.  The variable 
val_arg, being local, ceases to exist once the function fn finishes executing; 
at that time, the stack frame for fn is removed from the call stack, and the 
space where val_arg is stored could be used by another stack frame from another 
function call. 

Therefore, when *q is printed, the value at the address stored by q could be
anything.
*/
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int* fn(int *ptr_arg, int val_arg) {
	*ptr_arg += val_arg;
	int *new_ptr = new int;  // **Line 1
	*new_ptr = val_arg;      // **Line 2
    // REPLACEMENT:
    //int *new_ptr = &val_arg;
	return new_ptr;
}

int main() {
	int x = 20, y = 78, *p, *q;
	p = &x;
	q = fn(p, y);
	cout << x << " " << y << " " << *p << " " << *q;
}