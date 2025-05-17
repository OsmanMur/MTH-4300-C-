////////////////////////////////////////////////////////////////////////////////
// hw3_q4.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using std::cout; using std::cin; using std::endl;

// Definition of next_collatz() should go below.

/* Updates the value of x to the next Collatz number in the sequence
   @param x   A reference to an integer that represents the current number in the Collatz sequence
   @precondition   x > 0
   @condition  x is updated to x/2 if even or (3*x) + 1 if odd
*/
void next_collatz(int &x) {  
    if (x % 2 == 0) { // even
        x = x / 2; 
    } else { 		 // odd
        x = (3 * x) + 1; 
    }
}

// DO NOT MODIFY ANY CODE BELOW THIS LINE.  Write your function above.
int main() {
	cout << "Enter N: ";
	int N;
	cin >> N;
	while(N != 1){
		next_collatz(N);  // PAY CLOSE ATTENTION TO THIS LINE
		cout << N << " ";
	}	
}