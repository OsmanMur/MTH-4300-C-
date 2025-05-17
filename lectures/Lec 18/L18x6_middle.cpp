////////////////////////////////////////////////////////////////////////////////
// Middle
// Insert and Erase
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::vector <string> x = {"hello", "everyone", "I", "am", "a", "vector"};
    
    // Erases "everyone".  Expensive operation -- everything after is moved forward.
    x.erase(x.begin() + 1);

    // Inserts a new element at position 1, moving later elements back. Again, expensive.
    x.insert(x.begin() + 1, "EVERYONE");

    std::vector <string> other = {"INSERTING", "ELEMENTS", "IN", "MIDDLE"};

    // Places elements of `other` into `x`, starting at position 4. Other elements get moved back.
    // Three parameters: 
    // -- position in original list to begin insertion
    // -- iterator of first element to be inserted
    // -- iterator of one-past-the-last element to be inserted
    x.insert(x.begin() + 3, other.begin(), other.end());

    for(auto it = x.begin(); it < x.end(); ++it){
        cout << *it << " ";
    }

    return 0;  
}