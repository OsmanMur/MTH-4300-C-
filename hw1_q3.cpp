////////////////////////////////////////////////////////////////////////////////
// hw1_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::string;  


int main()
{
    cout << "Enter one word: ";
    string word;
    cin >> word;
    int i = 0;

    while (i < word.size()) {
        char letter = word[i];  
        char new_word = letter + 1;  //goes to the next letter 
        i++;
        cout << new_word ;
    }

    return 0;
}
