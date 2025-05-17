////////////////////////////////////////////////////////////////////////////////
// Exception
// Generating our own exceptions.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdexcept>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    double x;
    cout << "Enter x, which we will find the reciprocal of: ";
    cin >> x;
    if (x == 0) {
        throw std::domain_error("Why are you dividing by zero?");
    }
    cout << 1 / x << endl;

    int N;
    cout << "Enter the length of an array: ";
    cin >> N;
    if (N < 0 || N > 1'000'000) {
        throw std::length_error("That's too big! (Or negative)");
    } else {
        int* arr = new int[N];
    }

}