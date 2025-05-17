////////////////////////////////////////////////////////////////////////////////
// Ref
// Constant reference variables
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main () {
    int x = 15;
    const int &y = x;   // y refers to the same object as x, 
                        // but you cannot use the name y to modify this variable

    x += 2;     // OK! x =15 --> x = 17
    y += 3;     // ILLEGAL! y is a constant reference to x, so you can't change x through y

    const int a = 15;   // This object is constant: a's value won't change.
    int &b = a;         // Therefore, this declaration is illegal -- if b isn't
                        // const, the compiler would have trouble guaranteeing that
                        // a stays constant.
    
    const int &c = a;   // (But this would be fine.)

	return 0;   
}

