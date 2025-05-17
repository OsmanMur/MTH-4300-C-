////////////////////////////////////////////////////////////////////////////////
// hw4_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

/*
a. *q = 14 is dangerous.  q was never initialized, so it contains a "garbage" address.  
   The piece of memory with address held in q may not be in the address space reserved
   for the running program; and so assigning this memory the value of 14 may lead to a
   segmentation fault.
b. 8 50 30 51 50: the last four lines before the "cout" do the following:
   p is assigned the address of y[0]; 
   q is assigned the address of y[2]; 
   y[0] is assigned y[2 + 1];
   y[2] is assigned y[0] + 1
*/

int main() {
    int x = 4, *p, *q;
    int y[4] = {10, 30, 40, 50};

    p = &x;
    *p = 8;
    //*q = 14;
    p = y;
    q = p + 2;
    *p = *(q + 1);
    *q = *p + 1;

    cout << x << " " << y[0] << " " << y[1] << " " << y[2] << " " << y[3];
}