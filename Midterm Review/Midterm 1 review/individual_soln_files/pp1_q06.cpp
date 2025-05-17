// Problem 6
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int entry;
    bool win = false;
    for (int i = 1; i <= 10; ++i) {
        cout << "Entry? ";
        cin >> entry;
        if (entry == 7 || entry == 11) {
            cout << "WIN";
            win = true;
            break;
        }
    }
    if (!win) {
        cout << "LOSE";
    }
}
