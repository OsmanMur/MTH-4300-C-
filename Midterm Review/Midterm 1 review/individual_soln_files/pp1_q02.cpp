// Problem 2
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string input;
    cin >> input;
    for (int idx = 0;  idx <= input.size() - 1; ++idx) {
        if (input[idx] >= 'a' && input[idx] <= 'z') {
            input[idx] += 'A' - 'a'; //  'A' - 'a' is the ASCII difference between a lowercase character
                                     //  and its uppercase equivalent
        }
    }
    cout << input;
}