////////////////////////////////////////////////////////////////////////////////
// Fn
// A reminder about function calls and the stack
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl;


///// When we outline this in our stack diagram, you will see the value 1234.5678 
///// get copied.  The point being made is that it take me time to copy this long 
///// number to the argument `a` when I illustrate the program ---- and it similarly 
///// takes your computer time to copy a value to an argument.

double my_fn(const double &a) {
    double b = 100 * a;
    return b;
}

int main () {
    double x = 1234.5678, y;
    y = my_fn(x);
    cout << y;
}

