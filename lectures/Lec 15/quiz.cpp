#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Car {
public:
    string model;
    double cost;

    Car(string, double ); // constructor declaration

    bool operator==(Car); // better practice
};

// Constructor defined outside the class
Car::Car(string m, double c) : model{m}, cost{c} {}

// Equality operator
bool Car::operator==(Car rhs) {
    return (model == rhs.model);
}

int main() {
    Car a("Toyota", 20000);
    Car b("Toyota", 25000);
    Car c("Honda", 18000);

    cout << (a == b) << endl; // should print 1 (true)
    cout << (a == c) << endl; // should print 0 (false)

    return 0;
}

