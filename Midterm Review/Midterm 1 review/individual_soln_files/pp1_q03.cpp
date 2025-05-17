// Problem 3 

/* 
Typically, an int in C++ holds a 32-bit value; this number can go from to -(2^31) to 2^31 - 1.
In this problem, as you keep adding one to the original value, you eventually surpass that threshold.
What happens next is undefined behavior, but a very typical circumstance is that adding 1 to the int value
2^31 - 1 "wraps around" to -(2^31), and then the addition by 1 continues.  
*/

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main(){
    int x = 2147483600;
    for(int i = 0; i <= 1000; ++i) {
        std::cout << x + i << std::endl;
    }
}