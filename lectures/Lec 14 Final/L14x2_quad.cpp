////////////////////////////////////////////////////////////////////////////////
// Quad
// A first example of polymorphism
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

void quad(int x) {
    cout << "INT! Four times " << x << " equals " << 4*x << endl; 
}

void quad(float x) {
    cout << "FLOAT! Four times " << x << " equals " << x + x + x + x << endl; 
}

void quad(double x) {
    cout << "DOUBLE! Four times " << x << " equals " << 4*x << endl; 
}

void quad(string x) {
    cout << "STRING! Four times " << x << " equals " << x + x + x + x << endl; 
}


int main () {
    // OBSERVE WHICH FUNCTION NAMED "QUAD" GETS CALLED IN EACH CASE
    // ALSO, WHAT HAPPENS WHEN THE int VERSION OF quad() IS COMMENTED OUT?
    quad(12);
    quad(2.5);

    double a = 25;   
    quad(a);

    quad("hello");
	return 0;   
}

