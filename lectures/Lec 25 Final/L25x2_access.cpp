////////////////////////////////////////////////////////////////////////////////
// Access
// Highlighting various forms of inheritance
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Base {
private:
    int x;
protected:
    string y;
public:
    char z;
    Base(): x{14}, y{"hello"}, z{'?'} {}
};

// Are x, y, z accessible within each of these inherited classes?
// Are they public, protected, or private?

class Pub: public Base {
    // x: inaccessible
    // y: protected
    // z: public
    void f() {x; y; z;}
};

class Prot: protected Base {
    // x: inaccessible
    // y: protected
    // z: protected
    void f() {x; y; z;}
};

class Indirect: public Prot {
    // x: inaccessible
    // y: protected
    // z: protected
    void f() {x; y; z;}
}; 

int main() {
    // Which ones are accessible in main?
    Pub p1;
    p1.x;  
    p1.y;  
    p1.z;  // <- only this one

    Prot p2;
    p2.x;  
    p2.y;  
    p2.z;

    Indirect i;
    i.x;
    i.y;
    i.z;
}