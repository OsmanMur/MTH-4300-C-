////////////////////////////////////////////////////////////////////////////////
// Scope
// The variable p is declared in block scope, so it no longer exists when we 
// arrive at the last line.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int x;
    cout << "Enter an int: ";
    cin >> x;

    if (x > 0) {
        string p = "Positive";
    } else if (x < 0) {
        string p = "Negative";
    } else {
        string p = "Zero";
    }

    // The variable p below will never have been declared in this scope.
    cout << p << endl;
    return 0;
}