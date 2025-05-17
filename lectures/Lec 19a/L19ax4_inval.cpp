////////////////////////////////////////////////////////////////////////////////
// Inval
// Beware of iterator invalidation
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::vector <string> x(4); // Allocates a vector with capacity 4.
    x.push_back("A");

    auto it = x.begin();  // `it` points to the address of the 
                          // first entry of the heap-allocated array

    for(int i = 1; i < 1000; ++i){ // Almost certainly all this pushing back
        x.push_back("A");          // will trigger a reallocation
    }
    
    cout << *it << endl;  // Now, `it` points to old memory, which leads to
                          // undefined behavior.

    return 0;  
}