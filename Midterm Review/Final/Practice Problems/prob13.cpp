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