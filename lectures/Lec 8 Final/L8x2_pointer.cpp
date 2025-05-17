////////////////////////////////////////////////////////////////////////////////
// Pointer
// An introduction to pointer variables and the dereference operator.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
    int x = 937357;
    
    // &x is the ADDRESS of x.
    cout << "The value of x is " << x << " and the address of x is " << &x << endl;
    
    int *p;  // p is a POINTER to an integer: it holds the address of an int object
    p = &x;  // `&x` is a perfect value for p to hold.            
    cout << "The value of pointer p is " << p << endl;
    
    // *p is the value held at the address p.
    cout << "The value of *p is " << *p << endl;    
    return 0;   
}


