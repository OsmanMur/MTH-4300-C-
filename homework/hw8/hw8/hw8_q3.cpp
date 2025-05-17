// HW 8, Question 3
#include <iostream>
#include <string>
#include <stack>

using std::cout; using std::cin; using std::endl; using std::string;

///////// Write the balanced function.  Use a stack.

bool balanced(const string& str) {
    std::stack<char> my_stack;

    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];

        if (c == '(' || c == '[') {
            my_stack.push(c);
        } else if (c == ')' || c == ']') {
            if (my_stack.empty()){
                return false;
            }
            if ((c == ')' && my_stack.top() == '(') || (c == ']' && my_stack.top() == '[')) {
                my_stack.pop();
            } else {
                return false;
            }
        }
    }

    return my_stack.empty();
}


int main() {
    string bal1 = "(2 + [ 3 - (4*2) + 5] - 6)";
    string bal2 = "(((x + [y + (z * [w - [1]])])) + [4])";
    string bal3 = "()";
    string bal4 = "";
    string unbal1 = "(x[y)z]";
    string unbal2 = "(1 + (2 + (3 + 4]]]";
    string unbal3 = "1]";
    string unbal4 = "(((1 + 2";

    cout << "You should see\n1111\n0000\non the next two lines:\n";
    cout << balanced(bal1) << balanced(bal2) << balanced(bal3) << balanced(bal4) << endl; 
    cout << balanced(unbal1) << balanced(unbal2) << balanced(unbal3) << balanced(unbal4) << endl; 
}

