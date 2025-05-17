// Problem 4
#include <iostream>
#include <string>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main(){
    std::ifstream file("script.txt"); 
    if (file.fail()) {
        cout << "Cannot open file" << endl;
        return 1;
    }

    string line;
    string longest_line = "";
    while (std::getline(file, line)){
        if (line.size() > longest_line.size()) {
            longest_line = line;
        }
    }
    file.close();
    cout << longest_line;
    return 0;
}