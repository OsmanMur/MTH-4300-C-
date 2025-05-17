#include <iostream>

using namespace std;

class Character {
private:
    string name;
public:
    Character(string n): name{n} {}
    void print() const { cout << name << " says \"Hello!\"" << endl; } 
};

class CharWithItems: public Character {
private:
    int num_items;
    string *arrptr;
public:
    CharWithItems(string n, int ni): Character(n), num_items{ni}, arrptr{new string[ni]} {}

    void insert(string val, int idx) {
        if (0 <= idx && idx < num_items) { arrptr[idx] = val; }
    }

    void print() const {
        Character::print();
        cout << "Item list: ";
        for (int i = 0; i < num_items; ++i) { cout << arrptr[i] << " "; }
        cout << endl;
    }
    ~CharWithItems() { delete[] arrptr; }
};

int main() {
    Character *c1 = new Character("Alice");
    Character *c2 = new CharWithItems("Bob", 100);
    delete c1;
    delete c2;
}

/****************SOLUTION*************************

When delete c2 is called, since the destructor is not virtual, the destructor from the class Character is called rather than the destructor
from the class CharWithItems.  Since ~Character does not delete the memory that arrptr points to, that memory will be leaked.

Solution: add 
 
virtual ~Character() {}

to the Character class.

*************************************************/