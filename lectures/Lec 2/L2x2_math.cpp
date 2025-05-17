////////////////////////////////////////////////////////////////////////////////
// Math
// Peculiarities of ints and doubles related to division and mod
// Also, some basic math functions (and an uninitialized variable)
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>     // include the library for basic math functions.

int main() {
    std::cout << "17 / 7 = " << 17 / 7 << std::endl << "-12 / 9 = " << -12 / 9 << std::endl; 

    std::cout << "Which of these will give 0.5?" << std::endl;
    std::cout << "1.0 * 5 / 10 : " << 1.0 * 5 / 10  << std::endl;          
    std::cout << "5 / 10 * 1.0 : " << 5 / 10 * 1.0 << std::endl;          
    std::cout << "static_cast<double>(5) / 10 : " << static_cast<double>(5) / 10 << std::endl;      
    std::cout << "static_cast<double>(5 / 10) : " << static_cast<double>(5 / 10) << std::endl;  //ints are being divided first then converted thus answer is an int
    
    std::cout << "-17 % 10 = " << -17 % 10 << " (in Python, -17 % 10 = 3)" << std::endl;
    
    std::cout << "pow(10, 3) = " << std::pow(10, 3) << std::endl;      // Basic
    std::cout << "sin(3.14/6) = " << std::sin(3.14/6) << std::endl;    // math
    std::cout << "exp(1) = " << std::exp(1) << std::endl;              // functions
    std::cout << "log(2.7) = " << std::log(2.7) << std::endl;          // 


    double garbage;
    std::cout << "garbage = " << garbage << std::endl;  // Who knows?????

	return 0;
}