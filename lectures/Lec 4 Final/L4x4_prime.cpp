////////////////////////////////////////////////////////////////////////////////
// Prime
// Featuring the efficient is_prime function
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
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

// Observe the commenting style above: it describes WHAT is_prime() does rather than HOW it does it.

// Why is sqrt(n) a good upper bound?  Whenever you factor an integer n, both factors can't be greater that sqrt(n),
// or else their product would be > n.  Therefore, if n has a factor, you would encounter it by the time factor become sqrt(n).

int main() {
	for (int i = 0; i <= 35; ++i){
		cout << i << " " << is_prime(i) << endl;
	}
	cout << "Is 2 prime? " << is_prime(2) << endl;
	cout << "Is 17 prime? " << is_prime(17) << endl;
	cout << "Is 35 prime? " << is_prime(35) << endl;
	cout << "Is 49 prime? " << is_prime(49) << endl;
	return 0;
}