////////////////////////////////////////////////////////////////////////////////
// Delete
// How to deallocate memory
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    double *var = new double;
    *var = 5;
    delete var;  // Delete single heap-allocated variable

    string *arr = new string[100];
    delete[] arr;  // Delete an entire heap-allocated array -- you don't have to provide the length.
    
    cout << "Done" << endl;
    return 0;
}
