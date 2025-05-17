////////////////////////////////////////////////////////////////////////////////
// copies.cpp
// Observe that x and y are linked
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "list.h"

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    List x(10), y(10);
    x.append("Hello");
    x.append("Goodbye");
    
    // A COPY!!!
    y = x;
    x[0] = "Replace"; // This changes the shared array

    cout << "x is: ";
    x.print();

    cout << "y is: ";
    y.print(); // y is changed too!
    return 0;
}