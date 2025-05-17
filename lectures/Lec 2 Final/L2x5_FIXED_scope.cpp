////////////////////////////////////////////////////////////////////////////////
// Scope - ALTERNATIVE FIXED VERSION
// This is the Scope program, with minimal changes to turn it into a correctly
// working program.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int x;
    cout << "Enter an int: ";
    cin >> x;

    string p;  // DECLARE p IN main()

    if (x > 0) {
        p = "Positive";   // Do NOT redeclare p.  This way, the variable p refers to the same variable as declared above.
    } 
    else if (x < 0) {
        p = "Negative"; 
    } 
    else {
        p = "Zero"; 
    }

    cout << p << endl;
    return 0;
}