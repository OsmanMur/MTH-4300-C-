// Problem 7
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int N;
    cin >> N;
    for (int row = 1; row <= N; ++row) {
        // first_symbol is the first printed symbol in a row (the "odd" entries in the row)
        // second_symbol is the second printed symbol in a row (the "even" entries in the row)
        char first_symbol = '*', second_symbol = ' ';
        if (row % 2 == 0) {
            first_symbol = ' ';
            second_symbol = '*';
        }
        for (int col = 1; col <= N; ++col) {
            if (col % 2 == 1) {
                cout << first_symbol;
            } else {
                cout << second_symbol;
            }
        }
        cout << endl;
    }
}

// Slicker Solution
/* int main() {
    int N;
    cin >> N;
    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col) {
            if (row % 2 == col % 2) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
*/
