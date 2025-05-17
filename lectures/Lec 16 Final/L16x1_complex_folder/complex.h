////////////////////////////////////////////////////////////////////////////////
// complex.h
// Header file for the Complex class
////////////////////////////////////////////////////////////////////////////////

#ifndef COMPLEX_H   // INCLUDE GUARD TO PREVENT MULTIPLE DECLARATIONS
#define COMPLEX_H   // INCLUDE GUARD TO PREVENT MULTIPLE DECLARATIONS

// (The first line checks if the preprocessor has seen this symbol "COMPLEX_H" before. 
//  If not, the second line introduces that symbol.
//  That way, if this file accidentally gets included again, the symbol WILL be recognized
//  and the preprocessor will know not to insert this code a second time.)


#include <iostream>

using std::cout; using std::cin; using std::endl;

class Complex {														
private:			
	double re;
	double im;
public:
	// Put default values in the HEADER file
	// Put initializer list and body in IMPLEMENTATION file
	Complex(double = 0, double = 0); 

	// We've (somewhat arbitrarly) decided to implement
	// + and * as MEMBERS
	// and  == as a NON-MEMBER (friend)
	Complex operator+(const Complex&) const; 	
	Complex operator*(const Complex&) const; 
	friend bool operator==(const Complex&, const Complex&);   // Trailing "const" would make no sense 
															  // for non-member functions. 

	// << and >> CANNOT be members, MUST be friends.	
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
};

#endif  // INCLUDE GUARD TO PREVENT MULTIPLE DECLARATIONS