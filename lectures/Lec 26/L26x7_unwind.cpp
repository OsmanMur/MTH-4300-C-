////////////////////////////////////////////////////////////////////////////////
// Unwind
// Let's view what happens when exceptions are thrown.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

// Just like an int, except it makes noise when constructed or destructed.
class LoudInt {
    int x;
public:
    LoudInt(int n): x{n} {cout << "Int " << x << " comes alive." << endl;}
    ~LoudInt() { cout << "Int " << x << " is disappearing." << endl; }
};

void f() {
    LoudInt a(20);
    throw std::runtime_error("Here is the .what() message!");
    cout << "The third line of f.\n";
}

void g() {
    LoudInt b(10);
    f();
    cout << "The third line of g.\n";
}

int main() {
    try {
        g();
    } catch (std::runtime_error ex) {
        cout << ex.what() << endl;
    }
}