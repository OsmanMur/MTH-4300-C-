////////////////////////////////////////////////////////////////////////////////
// nfactors.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


using std::cout; using std::cin; using std::endl; using std::string;

/* Returns number of factors for a given integer.
   @param n  the integer we want to find the factors of.
   @return the count of the number of factors integer n has.
*/
int num_factors(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {  
        if (n % i == 0) { 
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    int counter = 1;
    cout << "Enter a positive integer: ";
    cin >> n;

    while(num_factors(counter) != n){
        counter += 1;
    }

    cout << "The least postive integer which has exactly " << n << " postive integers factors is " << counter << endl;
    return 0;
}
