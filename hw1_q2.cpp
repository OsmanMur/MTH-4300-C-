////////////////////////////////////////////////////////////////////////////////
// hw1_q2.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <random>
#include <iostream>
#include <cmath>
using std::cout; using std::cin; using std::endl; using std::string;  

int main() {
    std::random_device random_num; // Gets a random number from hardware, and uses it to "seed" the
    std::mt19937 my_gen(random_num()); // 19937-bit state Mersenne Twister pseudo-random number generator.

    std::uniform_real_distribution<double> my_distr(0.0, 1.0);
    double x = my_distr(my_gen);
    double y = my_distr(my_gen);

    cout << "Here's the value of sin(2πx)√(-2 ln y) with randomly generated x and y: " << std::sin(2 * M_PI * (x)) * std::sqrt(-2 * std::log(y))<< std::endl;
    return 0;
}