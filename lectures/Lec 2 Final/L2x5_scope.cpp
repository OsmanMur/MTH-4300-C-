////////////////////////////////////////////////////////////////////////////////
// Scope
// The variable p is declared (repeatedly) in block scope, so it no longer 
// exists when we arrive at the last line.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int x;
    cout << "Enter an int: ";
    cin >> x;

    if (x > 0) {
        string p = "Positive"; // This variable p will "exist" from line 18 to line 19
    } 
    else if (x < 0) {
        string p = "Negative"; // This variable p will "exist" from line 21 to line 22
    } 
    else {
        string p = "Zero"; // This variable p will "exist" from line 24 to line 25
    }

    // The variable p below will never have been declared in this scope.
    cout << p << endl;
    return 0;
}