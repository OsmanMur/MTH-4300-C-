// Problem 15 
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* Returns `s` with stars inserted between every two charcaters.
*/
string addstar(string s) {
    if (s.size() <= 1) {
        return s;
    }
    string out = "";
    return out + s[0] + '*' + addstar(s.substr(1));
}

int main() {
    cout << addstar("a") << endl;
    cout << addstar("ab") << endl;
    cout << addstar("abcdefgh") << endl;
}
