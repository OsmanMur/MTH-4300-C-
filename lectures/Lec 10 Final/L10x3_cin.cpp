////////////////////////////////////////////////////////////////////////////////
// Cin
// What will happen when you enter in various inputs?
////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    int num1;
    double num2;
    char letter;
    string word;
    
    cout << "Enter an int, double, char and string: ";
    cin >> num1 >> num2 >> letter >> word;  // This is equivalent to
                                            // cin >> num1; cin >> num2; cin >> letter; cin >> word;

    cout << "num1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;
    cout << "letter is: " << letter << endl;
    cout << "word is: " << word << endl;    

    return 0;                                    
}

