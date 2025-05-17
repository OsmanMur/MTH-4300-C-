////////////////////////////////////////////////////////////////////////////////
// hw1_q6.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
    int entry;
    cout << "Number? ";
    cin >> entry;

    int consecutive_equal_entries = 1;
        
    while (consecutive_equal_entries < 3) {
        int new_entry;
        cout << "Number? ";
        cin >> new_entry;
        if (new_entry == entry) {
            ++consecutive_equal_entries;
        } else {
            consecutive_equal_entries = 1;
        }
        entry = new_entry;
    }
    cout << "THREEPEAT!" << endl;
    return 0;
}