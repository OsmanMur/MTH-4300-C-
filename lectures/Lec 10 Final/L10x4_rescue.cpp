////////////////////////////////////////////////////////////////////////////////
// Rescue
// Rescuing cin from an input failure!
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <limits>

using std::cout; using std::cin; using std::endl; 

int main () {
    int x;

    cout << "Enter an int for x: ";
    cin >> x;

    while (cin.fail()) {
        cin.clear();    // Repair cin's state...
        cin.ignore(INT_MAX, '\n');  // ...and dump out lingering characters
        
        cout << "That's no number. Try again: ";
        cin >> x;
    }
    // Without cin.clear(), the value of cin.fail() would never change, and cin would
    // remain in fail state.  So cin >> x would get skipped, and the loop would run forever.

    // Without cin.ignore(), the bad input that the user typed would remain in the cin stream.
    // cin.clear() would cause the line cin >> x in the loop to function, but it would load in 
    // the bad data that is still in the cin stream, and immediately fail again, which also
    // would cause an infinite loop.

    cout << "Congratulations, you successfully entered " << x << ".  Way to go.";
    
    return 0;
}
