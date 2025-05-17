// Problem 10
#include <iostream>
#include <string>
#include <random>

using std::cout; using std::cin; using std::endl; using std::string;


int main() {
    std::random_device rand_dev;
    std::mt19937 gen( rand_dev() );
    std::uniform_real_distribution<>  dist(0.0, 1.0);
    double x[10][10];
    for (int row = 0; row <= 9; ++row) {
        for (int col = 0; col <= 9; ++col) {
            x[row][col] = dist(gen);
        }
    }

    for (int row = 0; row <= 9; ++row){
        double max = x[row][0];
        for (int col = 1; col <= 9; ++col) {
            if (x[row][col] > max){
                max = x[row][col];
            } 
        }
        cout << max << endl;
    }
}
