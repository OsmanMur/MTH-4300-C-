////////////////////////////////////////////////////////////////////////////////
// hw1_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    cout << "Enter a word: ";
    string word;
    cin >> word;
    
    for (int idx = 0; idx < word.size(); ++idx) {
        if (word[idx] == 'z' || word[idx] == 'Z') {
            word[idx] -= 25;
        } else {
            ++word[idx];
        }
    }
    cout << word;
    return 0;
}