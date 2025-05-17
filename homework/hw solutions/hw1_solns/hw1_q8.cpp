////////////////////////////////////////////////////////////////////////////////
// hw1_q8.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string st_orig, second;
    cout << "Enter a string: ";
    cin >> st_orig;
    cout << "Enter another string: ";
    cin >> second;

    char orig_letter, replacement;
    bool found_replacement = false;

    for (int i = 0; i < st_orig.size(); ++i) {
        if (st_orig[i] != second[i]) {
            orig_letter = st_orig[i];
            replacement = second[i];
            found_replacement = true;
            break; 
        }
    }

    // If the replacement letters have been found, swap every appearance in
    // `st_orig`, and see if the result equals `second`

    if (!found_replacement) {
        cout << "NO SPIN";
    } else {
        for (int i = 0; i < st_orig.size(); ++i) {
            if (st_orig[i] == orig_letter) {
                st_orig[i] = replacement;
            }
        }
        if (st_orig == second) {
            cout << "SPIN";
        } else {
            cout << "NO SPIN";
        }
    }
    return 0;
}