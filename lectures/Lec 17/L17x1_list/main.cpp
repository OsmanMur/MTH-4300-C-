////////////////////////////////////////////////////////////////////////////////
// main.cpp
// A typical client program
////////////////////////////////////////////////////////////////////////////////

#include "list.h"

int main() {
    List x(4); // calls reserve and bumps it up to capacity 8
    
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

    //list x(4) goes out of scope here
}