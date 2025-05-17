#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class One { 
public:          
    void f() { 
        g();  
        cout << "One::f" << endl; 
    }
    void g() {       
        cout << "One::g" << endl; 
    }   
    virtual void h() {
        cout << "One::h" << endl; 
    }  
};  

class Two: public One {  
public:          
    void g() {
        cout << "Two::g" << endl; 
    }   
    virtual void h() {
        f(); 
        cout << "Two::h" << endl; 
    } 
};  

class Three: public Two {  
public:   
    virtual void h() { 
        g(); 
        cout << "Three::h" << endl; 
    } 
};  

int main() {   
    One* a = new Two();   
    a->h();   
    cout << "----" << endl;  
    a->g();   
    cout << "----" << endl;   
    One* b = new Three();   
    b->h();   
    cout << "----" << endl;   
    b->f();    
}

/******************SOLUTION********************
a. First printout: since h() is virtual, and the dynamic type of a is Two*, a->h() calls Two::h().  
This function calls Two's version of f(); since there is no implementation of f() in Two, 
f() is inherited from One, so One::f() must be called.  
And since this function is implemented in One, the call to g() will be bound to One::g().
So: 
One::g, One::f, Two::h

Second printout: since g() is NOT virtual, and the static type of a is One*, a->g() calls One::g().
Hence:
One::g

Third printout: since h() is virtual, and the dynamic type of b is Three*, b->h() calls Three::h().  
This function calls Three's version of g(); since there is no implementation of g() in Three,
Three inherits Two's version of g(), so Two::g() is called.  This leads to:
Two::g, Three::h

Fourth printout: since f() is NOT virtual, and the static type of b is One*, b->f() calls One::f().
And since this function is implemented in One, the call to g() is bound to One::g().  Therefore:
One::g, One::f

b. Now, every call to g() utilizes the version of g() determined by the dynamic type.  Since the
dynamic type of a is Two*, so in a->h() and a->g(), all calls to g() will call Two::g instead of 
One::g.  And since the dynamic type of b is Three*, and there is no implementation of g() in Three,
in b->h() and b->f(), all calls to g() will also call Two::g instead of One::g.  So:
Two::g
One::f
Two::h
----
Two::g
----
Two::g
Three::h
----
Two::g
One::f

**********************************************/