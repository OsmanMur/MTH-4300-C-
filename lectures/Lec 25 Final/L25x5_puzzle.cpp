////////////////////////////////////////////////////////////////////////////////
// Puzzle
// What print outs will appear below?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class A{
public:
    void f() {
        cout << "[A::f()]\n";
        other();
    }
    void other() {
        cout << "[A::other()]\n";
    }
};

class B: public A {
public:
    virtual void f() { // VIRTUAL KEYWORD HERE
        cout << "[B::f()]\n";
        other();
    }
    void other() {
        cout << "[B::other()]\n";
    }

};

class C: public B {
public:
    void f() {
        cout << "[C::f()]\n";
        other();
    }
    void other() {
        cout << "[C::other()]\n";
    }

};

class D: public C{
public:
    void f() {
        cout << "[D::f()]\n";
        other();
    }
    // NO other()
};


int main() {
    A* first = new B;
    cout << "first:\n";
    first->f();
    // *first's static type is A, but the dynamic type is B
    // Go to A::f() --> it's not virtual, so call A::f(), which will call A::g()

    B* second = new D;
    cout << "\nsecond:\n";
    second->f();
    // *second's static type is B, but the dynamic type is D
    // Go to B::f() --> it IS virtual, so call D::f(), which will call D::g()...which isn't implemented, so C::g() is called instead.

    C* third = new D;
    cout << "\nthird:\n";
    third->f();
    // *third's static type is C, but the dynamic type is D
    // Go to C::f() --> it IS virtual, as it hides B::f(), which is virtual.
    // So call D::f(), which proceeds as in the last case.

}