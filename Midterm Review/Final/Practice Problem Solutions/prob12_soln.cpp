#include <iostream>

using namespace std;

class Base {
protected:
    int x;
public:
    string y;
    Base(): x{0}, y{"Base"} {}
    void func() { cout << "[Base::f()] " << x << y << endl; }
    virtual void otherfn() = 0;                                     
};

class Deriv_one: public Base {
public:
    double extra;
    Deriv_one(): Base(), extra{3.14} {}
    void otherfn() { cout << "[Deriv_one::otherfn()] " << extra << endl; }                        
};

class DerDer: public Deriv_one {
public:
    DerDer(double value) { extra = value; }  
    void func() { cout << "[DerDer::funct()] " << endl;}
    void otherfn() { Deriv_one::otherfn(); cout << x << endl; }      
};

class Deriv_two: public Base {
public:
    Deriv_two() {}
    void func() { cout << "[Deriv_two::func()] " << x << y << endl; }                         
};

int main() {
    /*Base bb;        //
    bb.func();      // Block one
    cout << bb.y;   //*/
    
    /*Deriv_one d1d1; //
    d1d1.func();    // Block two
    d1d1.otherfn(); //
    cout << d1d1.y; //*/

    /*DerDer dd(2.718); //
    dd.func();        // Block three
    dd.otherfn();     //
    cout << dd.x;     //*/

    /*Deriv_two d2d2;  //
    d2d2.func();     // Block four
    d2d2.otherfn();  //
    cout << d2d2.y;  //*/
}

/*******************SOLUTION********************

Block one: the class Base is abstract, since it has a pure virtual method (virtual void otherfn() = 0).  Therefore, you cannot declare objects 
of this type. 

Block two: this code compiles.  It prints:

[Base::f()] 0Base
[Deriv_one::otherfn()] 3.14
Base

Block three: dd.x is not accessible in main().  x is a protected member of Base.  So it can be accessed in the implementations of
functions in inherited classes like Deriv_one and DerDer, but not in main() or other non-member functions.

Block four: again, Base is an abstract class, since it has the pure virtual method otherfn().  
But also, since Deriv_two inherits directly from Base, but doesn't provide an implementation of otherfn(), 
Deriv_two is ALSO pure virtual.  So, you cannot declare objects of type Deriv_two either.

***********************************************/