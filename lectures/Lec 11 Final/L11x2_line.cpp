////////////////////////////////////////////////////////////////////////////////
// Read
// Reading a file
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main () {
    // ROUND 1: let's print out the contents of each line.
    std::ifstream infile("lines.txt");

    string line;
    int count = 0;
    while(std::getline(infile, line)) {
        ++count;
        cout << "Line " << count << ": " << line << endl;
    }
    
    // ROUND 2: let's do a word count.
    // Since we want to start from the beginning of the file, let's
    // close the existing filestream, and create a new fresh one.
    
    infile.close();
    std::ifstream take_two("lines.txt");
    
    string word;
    int word_count = 0;
    while (take_two >> word) {
        ++word_count;
    }

    cout << "The file has " << word_count << " words.\n";

    take_two.close();
    return 0;
}
