#include <iostream>

using namespace std;


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
}