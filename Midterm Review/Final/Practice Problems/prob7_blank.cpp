#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int main() {
    ifstream file("postfix.txt");
    if (file.fail()) {
        throw runtime_error("File not opened");
    }
    
    // Answer should be 80.2571


}
