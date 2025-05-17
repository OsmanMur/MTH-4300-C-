////////////////////////////////////////////////////////////////////////////////
// main.cpp
// A typical client program
////////////////////////////////////////////////////////////////////////////////

#include "list.h"

int main() {
    List x(4);
    
    x.append("Alice");
    x.append("Bob");
    x.append("Carol");
    x.append("David");
    x.append("Evan");
    x.print();

    x[0] = "Frank";
    cout << "x[0]: " << x[0] << endl;

    cout << "x[6] (not valid, but should not crash program): " << x[6];
    return 0;    
}