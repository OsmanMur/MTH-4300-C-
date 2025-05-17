////////////////////////////////////////////////////////////////////////////////
// Dangle
// Some pointers which don't point to valid objects.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    int *ptr1;
    *ptr1 = 10;     // Undefined behavior: ptr1 is dangling
                    // ptr1 contains a random "address" so *ptr1 probably can't be written to.

    double *ptr2 = new double[100];
    delete[] ptr2;
    *ptr2 = 1.23;  // Another dangling pointer, due to the deletion.

    // This one is sneaky:
    string *a = new string;
    string *b;
    *a = "Hello";
    b = a;
    delete b;
    cout << *a << endl; // Since a and b contain the same address, 
                        // when I deallocate the object pointed to by b,
                        // a will point to the same dead object.

    return 0;   
}


