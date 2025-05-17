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