////////////////////////////////////////////////////////////////////////////////
// greentao.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; 

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
//an = a1 + d (n-1) // what is the end term??

/* Returns the count of a prime arithmetic sequence
    @param start      The first term of the sequence 
    @param com_diff   The common difference between terms
    @return           The number of terms in the sequence before encountering a non-prime
*/
int prime_seq(int start, int com_diff) {
    int count = 0;
    int term = start; 
    while (is_prime(term)) {    
        count++;               
        term += com_diff;     
    }
    return count; 
}


int main()
{
	int best_start = 0;
	int best_diff = 0;
	int max_length = 0;

    for(int i = 2 ; i < 1000; ++i){ // potential first terms
		if (is_prime(i)){
			for (int j= i+1; j < 1000; ++j){ // potential second terms
				if (is_prime(j)){
					int common_diff = j - i; 
					int length = prime_seq(i, common_diff);

					if (length > max_length) {  
						max_length = length;
						best_start = i;
						best_diff = common_diff;
					}
				}
			}
		}
	}
	// Print results
	cout << "Longest Length: " << max_length << endl;
	cout << "Sequence: ";
	int term = best_start;
	for (int i = 0; i < max_length; i++) {
		cout << term << " ";
		term += best_diff;
	}
		
	return 0;
}
