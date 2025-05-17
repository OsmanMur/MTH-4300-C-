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
    Base bb;        //
    bb.func();      // Block one
    cout << bb.y;   //
    
    Deriv_one d1d1; //
    d1d1.func();    // Block two
    d1d1.otherfn(); //
    cout << d1d1.y; //

    DerDer dd(2.718); //
    dd.func();        // Block three
    dd.otherfn();     //
    cout << dd.x;     //

    Deriv_two d2d2;  //
    d2d2.func();     // Block four
    d2d2.otherfn();  //
    cout << d2d2.y;  //
}