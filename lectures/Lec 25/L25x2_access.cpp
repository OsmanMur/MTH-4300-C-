////////////////////////////////////////////////////////////////////////////////
// Access
// Highlighting various forms of inheritance
////////////////////////////////////////////////////////////////////////////////

include <iostream>

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
    // x: inaccess
    // y: protected
    // z: public
    void f() {x; y; z;} // will be an error as x is private in Base and not accessible
};

class Prot: protected Base {
    // x: inaccess
    // y: protected
    // z: protected
    void f() {x; y; z;} // y becomes protected in Prot
};

class Indirect: public Prot {
    // x: inaccess
    // y: protected
    // z: protected
    void f() {x; y; z;} //
}; 

int main() {
    // Which ones are accessible in main?
    Pub p1;
    p1.x;   // never accessible
    p1.y;  // not accessible because its in main
    p1.z; // accessible

    Prot p2;
    p2.x;   // never accessible
    p2.y;  // not accessible because its in main : b/c y becomes protected in Prot
    p2.z; // not accessible because its in main : b/c z becomes protected in Prot

    Indirect i;
    i.x;   // never accessible
    i.y;  // not accessible because its in main : b/c y becomes protected in Prot
    i.z; // not accessible because its in main : b/c z becomes protected in Prot
}