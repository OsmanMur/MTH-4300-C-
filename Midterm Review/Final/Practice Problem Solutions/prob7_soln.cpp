#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stack>

using namespace std;

int main() {
    ifstream file("postfix.txt");
    if (file.fail()) {
        throw runtime_error("File not opened");
    }
    
    std::stack<double> operands;
    string token;
    while(file >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double y = operands.top();
            operands.pop();
            double x = operands.top();
            operands.pop();
            if (token == "+") {
                operands.push(x + y);
            } else if (token == "-") {
                operands.push(x - y);
            } else if (token == "*") {
                operands.push(x * y);
            } else {
                operands.push(x / y);
            }
        } else {
            operands.push(stof(token));
        }
    }
    cout << operands.top();    
}

