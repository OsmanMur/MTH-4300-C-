////////////////////////////////////////////////////////////////////////////////
// Heartbleed
// Heartbleed was the name for a vulnerability in the OpenSSL security library
// that was discovered in 2014.  The code below illustrates one of the ideas
// relevant to how this vulnerability could be exploited.
// Let's DEFINITELY run this one on cpp.sh -- I've seen pretty interesting 
// things there.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

/* Prints contents of array `message`
   @param message     Array containing content
   @param length      Number of entries in array
*/
void echo(char message[], int length) {
    for(int i = 0; i <= length - 1; ++i){
        cout << "message[" << i << "]: "  << *(message + i) << endl;
    }
}

int main() {
	char message[] = {'b', 'i', 'r', 'd'};
    echo(message, 500);
}