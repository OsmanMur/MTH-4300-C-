////////////////////////////////////////////////////////////////////////////////
// Hiding
// There are several different variables named george in this program.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    int x = 2;
    int george = 11;
    if (x == 2) 
    {
        int george = 22;  // This george is a DIFFERENT VARIABLE than the first one.  
                          // For example, it resides at a different location in memory.
        cout << "First print: " << george << endl;
        if (x > 0) 
        {
            int george = 33;   // And this is a THIRD variable with the same name.
            cout << "Second print: " << george << endl;
        }
        george += 5;  // Which version of `george` does this update?
        cout << "Third print: " << george << endl;
    }
    cout << "Fourth print: " << george << endl;

    return 0;
}