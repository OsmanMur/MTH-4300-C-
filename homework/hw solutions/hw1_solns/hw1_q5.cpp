////////////////////////////////////////////////////////////////////////////////
// hw1_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main() {
    cout << "Enter positive real number x: ";
    double x;
    cin >> x;
    double sum = 0;
    double num_terms = 0;
    while(sum <= x) {
        ++num_terms;
        sum += 1.0/num_terms;
    }
    cout << num_terms;
    return 0;
}