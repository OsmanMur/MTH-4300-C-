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
	return Complex(new_real_part, new_im_part);
}

Complex Complex::operator*(const Complex &rhs) const {
	double new_real_part = re * rhs.re - im * rhs.im;
	double new_im_part = re * rhs.im + im * rhs.re;
	return Complex(new_real_part, new_im_part);
}

// NO Complex:: ! 
bool operator==(const Complex &lhs, const Complex &rhs){
	return lhs.re == rhs.re && lhs.im == rhs.im;
}

std::ostream& operator<<(std::ostream &s, const Complex &z){
    s << z.re << " + " << z.im << "i";
    return s;
}

std::istream& operator>>(std::istream &s, Complex &z){
    char dump_plus, dump_i;  // Just need to clear + and i from input stream
    s >> z.re >> dump_plus >> z.im >> dump_i;
    return s;
}