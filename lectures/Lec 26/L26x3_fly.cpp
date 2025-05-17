////////////////////////////////////////////////////////////////////////////////
// Dynamic Cast
// Showcasing dynamic_cast.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class Animal {
public:
    Animal() {}
    virtual ~Animal() {}
};

class Bird: public Animal {
public:
    Bird() {}
    void fly() const { cout << "[Bird flying]\n"; }
};

class Fish: public Animal {
public:
    Fish() {}
    void swim() const { cout << "[Fish swimming]\n"; }
};

int main() {
    // THIS CODE DOESN'T WORK! Why?
    Animal* x = new Fish;

    Bird *ptr = dynamic_cast<Bird*>(x); //will return nullptr becase x is a Fish

    // x->fly(); dangerous code, because x is an Animal pointer!
    
    if(ptr) { // Checking for non-nullptr.
        cout << "Successful cast" << endl;
        ptr->fly();
    } else {
        cout << "Unsuccessful cast" << endl;
    }
}