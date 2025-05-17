////////////////////////////////////////////////////////////////////////////////
// hw3_q4.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using std::cout; using std::cin; using std::endl;



// Based on the line I've pointed out, this function MUST produce its desired result by
// a side effect (that means changing the value of an argument to the function directly,
// rather than using a return value).  Therefore: the parameter to the function needs to 
// be a REFERENCE parameter -- and the function should be a void function.


void next_collatz(int &input) {  // <--- KEY LINE !!!
    if (input % 2 == 0) {
        input /= 2;
    } else {
        input = 3*input + 1;
    }
}



int main() {
	cout << "Enter N: ";
	int N;
	cin >> N;
	while(N != 1){
		next_collatz(N);  // PAY CLOSE ATTENTION TO THIS LINE
		cout << N << " ";
	}	
}