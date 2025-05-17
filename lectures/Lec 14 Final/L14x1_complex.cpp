////////////////////////////////////////////////////////////////////////////////
// Complex
// Introducing the Complex class
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Complex {														
private:			
	double re;
	double im;
public:
	Complex(double, double);
	Complex(double = 0);  // Default parameter
	
	void display() const; 			// To be replaced with something better at a later date.
	
	// Let's implement +, *, ==
	Complex operator+(Complex);
	Complex operator*(Complex);

	// == as a non-member function, to illustrate how that works.
	// To have access to private members, we make this a friend:
	friend bool operator==(Complex, Complex);

};


int main () {
	Complex z1(4, 5); // USES FIRST CONSTRUCTOR
	Complex z2(3);    // USES SECOND CONSTRUCTOR
	Complex z3;       // NO ARGUMENTS --> USE SECOND CONSTRUCTOR WITH DEFAULT ARGUMENT

	z1.display();
	z2.display();
	z3.display();

	// Some things that we'll need to implement.

	z3 = z1 + z2;  z3.display(); // `z1.operator+(z2)` is equivalent to `z1+z2`
	Complex z4 = z1 * z2;  z4.display();
	if(z1 == Complex(4) + Complex(0,5)) { cout << "Both z1 and Complex(4) + Complex(0,5) represent 4+5i" << endl; }

	return 0;   
}


Complex::Complex(double a, double b): re{a}, im{b} {
}

// This function has a default parameter -- if `a` isn't specified, then it equals 0 
Complex::Complex(double a): re{a}, im{0} {
}

void Complex::display() const {
	cout << re << " + " << im << "i " << endl;
}

Complex Complex::operator+(Complex rhs) {
	double newre = re + rhs.re;
	double newim = im + rhs.im;
	return Complex(newre, newim);  // We use the constructor to create an anonymous Complex, to return.
}

Complex Complex::operator*(Complex rhs) {
	double newre = re * rhs.re - im * rhs.im;
	double newim = re * rhs.im + im * rhs.re;
	return Complex(newre, newim);  
}

// NOT a member function -- that means no `Complex::`, and two parameters
bool operator==(Complex lhs, Complex rhs) {
	return (lhs.re == rhs.re) && (lhs.im == rhs.im);
}



