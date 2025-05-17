////////////////////////////////////////////////////////////////////////////////
// hw3_q6.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTION
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Too few arguments!" << endl;
        return -1; // Used to signal termination under error conditions.
    }
    
    string prefix = argv[1];
    int num_files = std::stoi(argv[2]);

    for (int i = 1; i <= num_files; ++i) {
        string filename = prefix + std::to_string(i) + ".txt";
        std::ofstream empty_file(filename);
    }
    return 0;
}