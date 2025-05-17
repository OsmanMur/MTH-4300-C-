////////////////////////////////////////////////////////////////////////////////
// hw1_q1.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; 

int main() {
    double x, y;
    cin >> x >> y;
    double PI = 4 * std::atan(1); // This is my favorite way to compute pi --
                                  // arctan(1) = pi/4.  
    cout << std::sin(2 * PI * x) * std::sqrt(-2 * std::log(y));
    return 0;
}