////////////////////////////////////////////////////////////////////////////////
// hw1_q7.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using std::cout; using std::cin; using std::endl;

int main(){
    std::ofstream squarefile("squares.txt"); 
    for(int row = 1; row <= 200; ++row){
        for (int i = 1; i <= row; ++i) {
            squarefile << i*i << " ";
        }
        squarefile << endl;
    }
    squarefile.close();
    return 0;
}