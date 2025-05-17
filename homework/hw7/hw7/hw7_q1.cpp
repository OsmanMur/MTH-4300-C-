////////////////////////////////////////////////////////////////////////////////
// hw7_q1.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

// Write code which allows the user to enter in a sequence of names (you may assume no spaces in each name), until they
// enter the word STOP. Your program should print out the number of different names in the list (not including the STOP).
// For example, if the user entered in Alice Bob Alice Carol Bob Alice STOP the program should output 3, for there
// are three different names, Alice, Bob and Carol

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main() {

    vector<string> names;
    string input;
    int count;

    cout << "Enter Names: ";
    while (cin >> input) {
        if (input == "STOP") {
            break;
        }

        bool found = false;
        for (int i = 0; i < names.size(); ++i) {
            if (names[i] == input) {
                found = true;
                break;
            }
        }
        if (!found) {
            names.push_back(input);
        }
    }

    cout << names.size() << endl;
}