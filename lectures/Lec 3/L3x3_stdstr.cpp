////////////////////////////////////////////////////////////////////////////////
// Stdstr
// A little bit about strings
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>  

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    // If you mouse over the string literal in VS Code, you will see its type: an array of characters of size 6. 
    // However, this so-called "c-string" can be assigned to a std::string.
    string word = "Hello";     // c-strings have a null character so there will always be one more character than there actually is, so 6 instead of 5.

   // string broken = "COMMENT" + "THIS" + "OUT";    // Can't concatenate literal c-strings
    string greeting = word + " people";               // Concatenation works here because at least one part is a std::string
    cout << "greeting is: " << greeting << endl;

    // `.size()` gives length.
    // Watch what happens when we subtract 1 from the size of an empty string!
    cout << "The length of " << word << " is " << word.size() << endl;
    string empty = "";
    cout << "(Length of empty) - 1 = " << empty.size() - 1 << endl; // unsigned language meaning -1 or negeative numbers dont show up and wrap-around beahavior is different

    // Notice: we replace y[0] with a CHAR, not a string.
    word[0] = 'J'; // C-strings are not immutable
    cout << "NOW, word is: " << word << endl;  

    // .substr()            // takes in 5 characters
    string middle = greeting.substr(3, 5);     // A slice starting at index 3, with length 5.  
    cout << "middle is: " << middle << endl;

    return 0;
}