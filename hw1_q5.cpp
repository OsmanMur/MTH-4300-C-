////////////////////////////////////////////////////////////////////////////////
// hw1_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using std::cout; using std::cin; using std::endl; using std::string;  

int main()
{
    double sum = 0;
    double n;
    double i = 1;

    cout << "Enter a value: ";
    cin>>n;

    while(sum < n){
        sum += 1/i;
        i++;
    }
    cout<< "The minimal number of terms needed is: " << i-1; // since i intialized it as 1 to make the series make sense, I subtracted 1 to make the correct number of terms true.
    
    return 0;
}
