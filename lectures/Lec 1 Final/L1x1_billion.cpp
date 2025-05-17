////////////////////////////////////////////////////////////////////////////////
// Billion
// Let's watch how long it takes this program to sum from one to a billion.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now(); 
	

	int N = 1'000'000'000;
	long long sum = 0;
	for(long long i = 1; i <= N; ++i){
		sum += i;
	}
	std::cout << sum << std::endl;

	
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Total elapsed time: " << duration.count() << " seconds" << std::endl;
	return 0; 
}

