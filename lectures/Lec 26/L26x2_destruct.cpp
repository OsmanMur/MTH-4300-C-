////////////////////////////////////////////////////////////////////////////////
// Destruct
// When base class pointers point to derived class objects, it's very easy
// for the wrong destructor to get called -- and then memory leaks can happen.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Human {
protected:
    string name;
public:
    Human(string n): name{n} {}
    virtual ~Human() {
        cout << "Base class destructor getting called for " << name << "." << endl;
    }
};

class Parent: public Human {
protected:
    int num_children;
    string* child_list;
public:
    Parent(string n, int num_c): Human(n), num_children{num_c}, child_list{new string[num_c]} {}
    ~Parent() {
        cout << "Ok, deleting " << name << "'s children list now." << endl; 
        delete[] child_list;
    }
};


int main() {
    Parent *a = new Parent("Alice", 5);
    Human *b = new Parent("Bob", 5);

    // What gets deallocated?
    delete a;
    delete b;

    return 0;
}