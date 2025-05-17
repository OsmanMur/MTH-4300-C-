////////////////////////////////////////////////////////////////////////////////
// Iter
// The basics of iterators
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::vector <string> x = {"hello", "everyone", "I", "am", "a", "vector"};
    
    auto my_it = x.begin();  // In VS, mouse-over my_it to see the data type.
                             // That's why we use auto.

    // Iterators are, at their heart, pointers -- you still use * to get the associated values.
    cout << "First element: " << *my_it << endl;

    cout << "Third element: " << *(my_it + 2) << endl;

    cout << "Last element: " << *(x.end() - 1) << endl;

    // A loop:
    for(auto it = x.begin();  it < x.end(); ++it) {
        cout << *it << " ";
    }

    return 0;  
}