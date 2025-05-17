////////////////////////////////////////////////////////////////////////////////
// greentao.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION
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

int main(){
    int max_length = 1;
    int max_first_term = -1;
    int max_common_diff = -1; 
    for (int first_term = 2; first_term < 1000; ++first_term){
        if (is_prime(first_term) ){
            for (int second_term = first_term + 1; second_term < 1000; ++second_term){
                int length = prime_seq_length (first_term, second_term - first_term);
                if (length > max_length) {
                    max_length = length;
                    max_first_term = first_term;
                    max_common_diff = second_term - first_term;
                }
            }
        }
    } 
    cout << "Max length: " << max_length;
    print_seq(max_first_term, max_common_diff, max_length);
    // There is only one: length = 10, sequence = 199 409 619 829 1039 1249 1459 1669 1879 2089
    return 0;
}