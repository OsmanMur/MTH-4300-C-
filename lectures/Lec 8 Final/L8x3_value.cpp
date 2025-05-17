////////////////////////////////////////////////////////////////////////////////
// Value
// Practice with pointers
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
    int x = 1, y = 2;
    int *p, *q;
    
    p = &x;
    *p = 10;
    q = p;
    *q = 20;
    p = &y;
    *p = *q;
    
    //
    // What would print out if I printed the values of x, y, *p, and *q now?
    //
    cout << x << " " << y << " " << *p << " " << *q << endl;

    return 0;   
}


