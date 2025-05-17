////////////////////////////////////////////////////////////////////////////////
// Inaccess
// Inaccessible objects
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    new int[100]; // This is a bad idea.  It gets reserved, 
                  // but how will you refer to it, or deallocate it, later?

    // A more subtle hazard:
    int *x = new int[20], *y = new int[50];
    y = x;  // Now, x points to the length-20 array, and so does y.  
    // Who points to the length-50 array?  You can't read it, write to it, or even delete[] it!

    return 0;   
}


