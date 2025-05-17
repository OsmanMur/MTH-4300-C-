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
    
    infile.close(); // closing the file will reset the stream to the beginning of the file.

    // ROUND 2: let's do a word count.
    std::ifstream take_two("lines.txt");
    int word_count = 0;
    
    string word;
    while(take_two >> word) { // reads a word from the file and stores it in word.
                             // The >> operator will read until it finds whitespace, so it will stop at the space between "Hello" and "world!"
        ++word_count;
    }
    //
    // WHAT LOOP WOULD WE PUT HERE?
    //

    cout << "The file has " << word_count << " words.\n";

    take_two.close();
    return 0;
}
