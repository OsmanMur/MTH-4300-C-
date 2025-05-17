#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::string;

/* Tests an integer for primality
	@param n        Integer to be tested for primality
	@precondition   n >= 0
	@return         Whether or not n is prime.
*/
bool is_prime (int n) {
	if (n <= 1) {
		return false;
	} 
	for (int factor = 2; factor <= std::sqrt(n); ++factor) {
		if (n % factor == 0) {
			return false;
		}
	}
	return true;
}

int main() {
    
}

