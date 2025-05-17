////////////////////////////////////////////////////////////////////////////////
// hw3_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

/* 21
   23
   21 23 50

   First print: updates x first, then assigns that value to y, and this value
   gets printed.  So x = 21, y = 21, and 21 gets printed.
   
   Second print: y updates to 23, this value gets assigned to y, and then this
   value gets printed.  So x = 21, y = 23, z = 23, and 23 gets printed

   if statement: because of the single =, z gets assigned to 50; and this 
   evaluates as true.  So the third print runs.

   Third print: y++ only updates y after the evaluation of y.  Therefore,
   21 will print for x, 23 will print for y, and 50 will print for z.
   (After that line, y will have the value 24, but we will never see that 
   print.)
*/


#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    int x = 20, y = 30, z = 40;
    cout << (y = ++x) << endl;
    cout << (z = y += 2) << endl;
    if (z = 50) {
        cout << x << " " << y++ << " " << z << endl;
    }
}