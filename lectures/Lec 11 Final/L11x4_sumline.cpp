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

    while(std::getline(file, line)) {
        // Now `line` will contain a string with all the numbers on a particular line of the file.
        // We have to break this down, and add up the contents.  A stringstream should work well.
        std::stringstream breakdown;
        breakdown << line;

        // Now, we will read from the stream `breakdown` one "word" at a time.  These "words" should
        // of course be captured as ints, so that we can do math with them.
        int line_sum = 0;
        int grab_a_num;
        while (breakdown >> grab_a_num) {
            line_sum += grab_a_num;
        }
        cout << "Line sum is: " << line_sum << endl;
    }

    file.close();
    return 0;
}
