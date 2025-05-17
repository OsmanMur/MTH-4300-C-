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
    std::vector<int> primes;
    for(int i = 2; i < 1000; ++i){
        if(is_prime(i)) {
            primes.push_back(i);
        }
    }

    cout << "Enter N: ";
    int N;
    cin >> N;

    // We should probably use the binary search here, but whatever.
    int count = 0;
    for(auto it = primes.begin(); it != primes.end(); ++it) {
        if (*it > N) {
            break;
        }
        ++count;
    }
    cout << "pi(N) = " << count << endl;
}