////////////////////////////////////////////////////////////////////////////////
// Global
// Variables declared outside of any function body can be used anywhere
// below the declaration.  These global variables are discouraged.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;


int class_no = 4300;  // This is a global variable.  It can be used in main() below.
                      // Since this variable is unlikely to change as the program 
                      // progresses, this isn't an awful variable to declare globally,
                      // but for variables whose values change, making them global
                      // is likely to cause confusion.

int main() {
    cout << "This class is MTH " << class_no << endl;
    return 0;
}