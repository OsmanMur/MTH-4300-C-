////////////////////////////////////////////////////////////////////////////////
// Hiding
// There are several different variables named george in this program.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    int x = 2;
    int george = 11;
    if (x == 2) {
        int george = 22;
        cout << "First george: " << george << endl;
        if (x > 0) {
            int george = 33;
            cout << "Second george: " << george << endl;
        }
        cout << "Third george: " << george << endl;
    }
    cout << "Fourth george: " << george << endl;

    return 0;
}