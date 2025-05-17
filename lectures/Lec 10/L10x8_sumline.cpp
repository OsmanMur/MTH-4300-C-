////////////////////////////////////////////////////////////////////////////////
// Sumline
// Sum each line
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    std::ifstream file("numbers.txt"); 

    string line;
    while (std::getline(file, line)) {
        std::stringstream parse;
        parse << line;          // Load the whole line into a string stream... 
        int sum = 0, val;
        while(parse >> val) {   // ...then remove one number at a time
            sum += val;
        }
        cout << "Line sum is: " << sum << endl;
    }

    file.close();
    return 0;
}
