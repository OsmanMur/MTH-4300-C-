////////////////////////////////////////////////////////////////////////////////
// hw1_q4.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;  

int main()
{
    int x, y;
    cout<< "\n"<<"Enter two positive integers "<<endl;

    cout<<"Enter first integer: ";
    cin >> x;
    cout<<"Enter the second integer: ";
    cin >> y;

    
    int remainder;

    while ((x % y) > 0){
        remainder = x % y;
        x = y;
        y = remainder; 
    }

    cout<<"The Greatest Common Divisor is "<< y; 
    return 0;
}

