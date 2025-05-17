// Problem 9
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string arr[10];
    for (int idx = 0; idx <= 9; ++idx) {
        cout << "Enter a name: ";
        cin >> arr[idx];
    }
    for (int idx = 9; idx >= 0; --idx) {
        cout << arr[idx] << endl;
    }
}

