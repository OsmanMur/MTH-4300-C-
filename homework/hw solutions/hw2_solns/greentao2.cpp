////////////////////////////////////////////////////////////////////////////////
// greentao.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION 2
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; 

// The first given solution is inefficient, in that it recomputes the primality of the numbers from
// 1 to 1000 many times.  The code in main() below eliminates much of the repetition.  
// (One could go further and use the Sieve of Eratosthenes, but I'll refrain from that.)
//
// The solution here calls upon the same functions as the original solution.


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

/* Given a first term and common difference, returns the number of terms in the arithmetic sequence BEFORE the first non-prime.
	@param first    First term of arithmetic sequence
	@param diff     Common difference of arithmetic sequence
	@precondition   first >= 0, diff > 0
	@return         The number of prime terms in this sequence before the first non-prime.
*/
int prime_seq_length (int first, int diff){
    int term_count = 0;
    int term = first;
    while (is_prime(term)) {
        ++term_count;
        term += diff;
    }
    return term_count;
}

/* Prints the first few terms of an arithmetic sequence 
	@param first      First term of arithmetic sequence
	@param diff       Common difference of arithmetic sequence
    @param num_terms  Number of terms to display
*/
void print_seq(int first, int diff, int num_terms) {
    cout << endl;
    for (int i = 1; i <= num_terms; ++i) {
        cout << first + (i-1) * diff << " ";
    }
}

int main() {
    int precompute[1000]; // A list, which will certainly be of length less than 1000
    int num_primes = 0;  // The number of primes seen so far.
    for(int n = 2; n < 1000; ++n) {
        if (is_prime(n)) {
            precompute[num_primes] = n;
            ++num_primes;
        }
    }


    int max_length = 1;
    int max_first_term = -1;
    int max_second_term = -1; 
    
    // The following code loops through the list precompute, to find the first two terms of the sequence.
    for (int first_term_idx = 0; first_term_idx < num_primes; ++first_term_idx){
        for (int second_term_idx = first_term_idx + 1; second_term_idx < num_primes; ++second_term_idx){
            int first_prime = precompute[first_term_idx];
            int second_prime = precompute[second_term_idx];
                
            int length = prime_seq_length (first_prime, second_prime);
            if (length > max_length) {
                max_length = length;
                max_first_term = first_prime;
                max_second_term = second_prime;
            }
        }
    } 
    cout << "Max length: " << max_length;
    print_seq(max_first_term, max_second_term - max_first_term, max_length);
    return 0;
}