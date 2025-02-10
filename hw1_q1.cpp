////////////////////////////////////////////////////////////////////////////////
// hw1_q1.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::string;  


int main() {
	double x, y ;

    cout << "Enter a real number for x: "; 
    cin >> x;

    cout << "Enter a real number for y (between 0 and 1): "; 
    cin >> y;
	
	cout << "Here's the value of  sin(2πx)√(−2 ln y): " << std::sin(2 * M_PI * (x)) * std::sqrt(-2 * std::log(y))<< endl;
	
	return 0;
}