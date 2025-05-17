////////////////////////////////////////////////////////////////////////////////
// Read
// Reading a file
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    std::ifstream infile("readmenow.txt");

    std::string whole_line;
    std::getline(infile, whole_line);   // Everything before the '\n' is put into the variable.
                                        // The newline is also removed from the stream.

    int x;
    infile >> x;

    cout << "whole_line is: " << whole_line << endl;
    cout << "x is: " << x << endl;
    
    infile.close();
    return 0;
}
