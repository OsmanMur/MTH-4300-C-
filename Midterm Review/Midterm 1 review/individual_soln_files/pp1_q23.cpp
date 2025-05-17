// Problem 23
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::ifstream infile("script.txt");
    std::ofstream outfile("tpircs.txt");

    if (infile.fail()) {
        cout << "Cannot open file" << endl;
        return 1;
    }
    
    string line;
    while(std::getline(infile, line)) {
        string backwards = "";

        std::stringstream linestrm;
        linestrm << line;

        string word;
        while(linestrm >> word) {
            backwards = word + " " + backwards;
        }
        outfile << backwards << endl;
    }
    infile.close();
    outfile.close();
}
