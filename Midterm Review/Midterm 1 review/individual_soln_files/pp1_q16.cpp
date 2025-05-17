// Problem 16
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* Returns true if there is a two-character sequence which two times after position `start` */
bool dubdub(string entry, int start) {
    if (entry.size() - start <= 2) {
        return false;
    }
    for (int i = start + 1; i <= entry.size() - 2; ++i) {
        if (entry[i] == entry[start] && entry[i+1] == entry[start + 1]) {
            return true;
        }
    }
    return dubdub(entry, start + 1);
}

int main() {
    cout << dubdub("banana", 0) << endl;
    cout << dubdub("banana", 3) << endl;
    cout << dubdub("banana", 5) << endl;
    cout << dubdub("abcdebcx", 0) << endl;
    cout << dubdub("abcccde", 0) << endl;
}