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

    B* second = new D;
    cout << "\nsecond:\n";
    second->f();

    C* third = new D;
    cout << "\nthird:\n";
    third->f();
}