////////////////////////////////////////////////////////////////////////////////
// hw1_q7.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::string;  

int main()
{
    std::ofstream your_file_var("numbers.txt");  

    for(int i = 1; i<=200; ++i){
        for (int j = 1; j <= i ; ++j){
            your_file_var << j;
        }
        your_file_var << endl; 
    }
        

    your_file_var.close();

    return 0;
}
