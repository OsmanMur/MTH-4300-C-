#include <iostream>

using namespace std;

/*********************SOLUTION*********************/
class Vehicle {
protected:
    double capacity;
    double cargo_load;
public:
    Vehicle(double c): capacity{c}, cargo_load{0} {}
    bool load(double w) {
        if (w + cargo_load <= capacity) {
            cargo_load += w;
            return true;
        }
        return false;
    }
    double weight() {
        return cargo_load;
    }
};

class PassengerVehicle: public Vehicle {
protected:
    int seats;
    int seats_taken;
public:
    PassengerVehicle(double c, int s): Vehicle(c), seats{s}, seats_taken{0} {}
    double weight() {
        return cargo_load + 100*seats_taken;
    }
    bool seat() {
        if (seats_taken < seats) {
            ++seats_taken;
            return true;
        }
        return false;
    }
};
/**************************************************/

int main() {   
    Vehicle v1(100);
    v1.load(40);
    v1.load(50);
    v1.load(30);
    cout << v1.weight() << " (should be 90)\n";

    PassengerVehicle pv2(100, 2);
    pv2.seat();
    pv2.seat();
    pv2.load(30);
    cout << pv2.seat() << " " << pv2.weight() << " (should be 0 230)\n";
    /******* Answer to part c: ******************
    
    v3, declared as a Vehicle, only has memory reserved for the variables v3.cargo_load
    and v3.capacity.  So, those attributes from pv2 get copied into v3, with values 30 and 100,
    respectively.  When v3.weight() is called, it calls the version implemented in the Vehicle 
    class, which returns the value of v3.cargo_load, 30.
    
    ********************************************/
}