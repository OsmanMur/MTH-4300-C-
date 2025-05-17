// Problem 2
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string names[] = {"alice", "joe", "andrew", "bob", "carol", "charles"};
    int length = 6;
    char **table = new char*[length]; // why? ->  

    for (int idx = 0; idx < length; ++idx) {
        string word = names[idx];
        table[idx] = new char[word.size()]; //word.size() is the length of the string word
        for (int j = 0; j <= word.size() - 1; ++j) {
            table[idx][j] = word[j];
        }
    }

    // To delete after we are done:
    for (int idx = 0; idx < length; ++idx) {
        delete[] table[idx];
    }
    delete[] table;     
}