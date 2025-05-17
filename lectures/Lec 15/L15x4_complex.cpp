////////////////////////////////////////////////////////////////////////////////
// Complex
// The Complex class
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Complex {														
private:			
	double re;
	double im;
public:
	Complex(double = 0, double = 0);

	Complex operator+(const Complex&) const;
	Complex operator*(const Complex&) const;

	// == can be implemented as a member or non-member.  We go with non-member, to illustrate how.
	friend bool operator==(const Complex&, const Complex&); // A friend declaration of a non-member function
	friend std::ostream& operator<<(std::ostream&, const Complex&); 
	friend std::istream& operator>>(std::istream&, Complex&); 
};

std::ostream& operator<<(std::ostream&s, const Complex&z){ // A non-member function
	s << z.re << " + " << z.im << "i"; // Note: we can access private members of Complex because we are a friend
	return s; // Return the stream
}

std::istream& operator>>(std::istream&s,  Complex&z){ // 
	char dump; // We'll use this as place holder to dump the '+' and 'i' characters
	s >> z.re >> dump >> z.im >> dump; // Read in the real part, a plus sign, the imaginary part, and an 'i'
	return s;
}


int main () {
	Complex z1(4, 5); 
	Complex z2(3);    
	Complex z3;       

	z3 = z1 + z2;
	
	Complex z4 = z1 * z2;
	cout << "z3 is " << z3 << " and z4 is " << z4 << endl;

	if(z1 + z2 == z3) {
		cout << "z1 + z2 equals z3" << endl;
	}

	cout << "Enter a new value for z3: ";
	cin >> z3;
	cout << "z3 + z2 is " << z3 + z2 << endl;

	return 0;   
}

Complex::Complex(double a, double b): re{a}, im{b} {
}

Complex Complex::operator+(const Complex &rhs) const {
	double new_real_part = re + rhs.re;
	double new_im_part = im + rhs.im;
	Complex ans(new_real_part, new_im_part);
	return ans;
}

Complex Complex::operator*(const Complex &rhs) const {
	double new_real_part = re * rhs.re - im * rhs.im;
	double new_im_part = re * rhs.im + im * rhs.re;
	Complex ans(new_real_part, new_im_part);
	return ans;
}

// NO Complex:: ! 
bool operator==(const Complex &lhs, const Complex &rhs){
	return lhs.re == rhs.re && lhs.im == rhs.im;
}



// // WARNING: RIGHT-ISH, BUT NOT 100% CORRECT
// std::ostream operator<<(std::ostream s, Complex z) {
// 	s << z.re << " " << z.im;
// 	return s;
// 	}
// 	So, when you write cout << z2 << z3 where z2 and z3 are Complex,
// 	the following will happen, kind of:
// 	operator<<(cout, z2) is called;
// 	cout << z2.re << " " << z2.im is executed, adding thedoubles and string to the output stream (which probably gets
// 	flushed to the screen immediately) – C++ already knows how tocout these types;
// 	the function returns cout, so that cout << z3 will be executed.
// 	One issue: re and im are private! Not a problem – just add a friend
// 	declaration to the class. (You can’t overload << and >> as members.)

	//explain these notes:  https://www.learncpp.com/cpp-tutorial/93-overloading-the-io-operators/