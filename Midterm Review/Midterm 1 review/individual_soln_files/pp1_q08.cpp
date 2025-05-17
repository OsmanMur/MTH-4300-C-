// Problem 8
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

// Fact: the seventh perfect number is REALLY HUGE.  Hence, long long.
// (But don't wait for this program to finish!)
long long sum_factors (long long n) {
    int sum = 0;
    for (long long int i = 1; i <= n/2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    long long perf = 1;
    int count = 0;
    while (count < 7) {
        if (sum_factors(perf) == perf) {
            ++count;    
        }
        ++perf;
    }
    cout << perf - 1;
}
