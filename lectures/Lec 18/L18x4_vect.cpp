////////////////////////////////////////////////////////////////////////////////
// Vect
// Vector basics
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::vector <string> x = {"hello", "everyone", "I", "am", "a", "vector"};
    std::vector <string> y(6, "***");
    for(int i = 0; i < 6; ++ i){
        cout << x[i] << " " <<  y[i] << " ";
    }
    cout << "\n\n";
    x.push_back("about to throw an exception");
    for(int i = 0; i < 8; ++i){
        cout << x.at(i) << endl;
    }

    return 0;  
}