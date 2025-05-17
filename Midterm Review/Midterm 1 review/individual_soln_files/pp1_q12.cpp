// Problem 12
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* @precondition   n > 0 */
int num_digits(int n) {
    if (n <= 9) {
        return 1;
    } else {
        return 1 + num_digits(n/10);
    }
}

int main() {
    cout << num_digits(4) << endl;
    cout << num_digits(14) << endl;
    cout << num_digits(1000) << endl;
    cout << num_digits(999999) << endl;
}
