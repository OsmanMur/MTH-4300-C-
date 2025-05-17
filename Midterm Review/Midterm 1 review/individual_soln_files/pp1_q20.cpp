// Problem 20
#include <iostream>
#include <string>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    std::ifstream myfile("script.txt");
    if (myfile.fail()) {
        cout << "Cannot open file" << endl;
        return 1;
    }

    string line;
    while(std::getline(myfile, line)) {
        string name;
        for (int idx = 0; idx < line.size(); ++idx) {
            if (line[idx] == ':') {
                name = line.substr(0, idx);
                break;
            }
        }
        cout << name << endl;
    }
    myfile.close();
}
