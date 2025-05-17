////////////////////////////////////////////////////////////////////////////////
// Fn
// A function template
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

// The following function can apply to int, double, char, etc.
// `WhateverType` is a type variable, representing whatever type we wish to use
// this function on.
template<typename WhateverType>
WhateverType my_max(WhateverType x, WhateverType y) {
    if (x >= y) 
        return x;
    return y;
}


int main() {
    cout << my_max<int>(4, 7) << endl;
    cout << my_max<double>(5.1, 2.9) << endl;

    string x = "Banana", y = "apple", z = "cherry";
    // Type deduction: both arguments are strings in all examples.
    cout << my_max(x, y) << " " << my_max(x, z) << " " << my_max(y, z) << endl;

    // 5.1 and 2.9 get copied to int local variables.
    cout << my_max<int>(5.1, 2.9) << endl;
}
