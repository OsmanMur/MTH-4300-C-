
// Problem 13
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* @precondition    `begin` and `end` should lie between 0 and `s.size() - 1`,
                    unless begin >= end.
*/
bool is_palin(string s, int begin, int end) {
    if (begin >= end) {
        return true;
    } else if (s[begin] != s[end]) {
        return false;
    } 
    return is_palin(s, begin + 1, end - 1);
}

int main() {
    cout << is_palin("", 0, 0) << endl;  // true
    cout << is_palin("aba", 0, 1) << endl;   // true
    cout << is_palin("ab", 0, 1) << endl;   // false
    cout << is_palin("abcba", 0, 3) << endl;    // false
    cout << is_palin("abcba", 0, 4) << endl;    // true
    cout << is_palin("abczba", 0, 5) << endl;   // false
}

