////////////////////////////////////////////////////////////////////////////////
// hw1_q2.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
#include <random>

using std::cout; using std::cin; using std::endl; 

int main() {
    std::random_device my_ran_dev;
    std::mt19937 my_gen(my_ran_dev());
    std::uniform_real_distribution<> my_distr(0.0, 1.0);
        
    double x = my_distr(my_gen), y = my_distr(my_gen);
    double PI = 4 * std::atan(1);
    cout << std::sin(2 * PI * x) * std::sqrt(-2 * std::log(y));
    return 0;
}