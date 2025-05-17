////////////////////////////////////////////////////////////////////////////////
// Animal
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Animal {
public: 
    string name, species;
    Animal(string, string);
    void eat(string) const;
    void display() const;
};


Animal::Animal(string n, string s): name{n}, species{s} {
}

void Animal::eat(string foodtype) const {
    cout << name << " the " << species << " is eating " << foodtype << "s.\n";
}

void Animal::display() const {
    cout << name << " is a happy " << species << ".\n";
}

////////////////////////////////////////////////////////////////
// DERIVED CLASS
class Dog: public Animal {
public:
    string breed;
    Dog(string, string);
    void bark() const;
    void display() const; 
};

Dog::Dog(string n, string b): Animal(n,"Dog") , breed{b} {   //constuctor
}

void Dog :: bark() const {
    cout << "The dog says: WOOF WOOF! ";
}

void Dog :: display() const{
    cout << name << " is a happy " << breed << ".\n";
}




int main() {
    Animal a("Pigwidgin", "Bearded Dragon");
    a.display();
    a.eat("Carrot");
    
    Dog d("Kola", "Australian Shepard");
    d.eat("Kibble");
    d.display();
    d.bark();

    Animal doggy = d;
    // NOTE: THE FOLLOWING LINE DOESN'T WORK!  You can assign a Dog to an Animal, 
    // but when you do so, you only save the Animal attributes.

    // doggy.bark();

    return 0;
}

