////////////////////////////////////////////////////////////////////////////////
// Sstream
// Introduction to stringstreams
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    std::stringstream sstrm;
    string expr = "123 + 456";

    sstrm << expr;

    
    // Having loaded the contents of expr into sstrm, we can treat that
    // string kind of like cin to take it apart.
    int arg1, arg2;
    char dump; // A place to drop the "+" sign.
    sstrm >> arg1 >> dump >> arg2;

    cout << expr << " equals " << arg1 + arg2 << endl;
    
    return 0;
}
