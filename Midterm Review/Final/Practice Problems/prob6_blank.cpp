#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Vector-based stack









int main() {
    Stack<string> x;
    x.push("A");
    x.push("B");
    x.push("C");
    cout << x.peek();
    x.pop();
    x.pop();
    x.push("R");
    x.push("B");
    x.push("O");
    while (!x.is_empty()) {
        cout << x.peek();
        x.pop();
    }
}