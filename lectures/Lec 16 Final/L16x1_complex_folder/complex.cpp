////////////////////////////////////////////////////////////////////////////////
// complex.cpp
// Implementation of the Complex class functions and friends
////////////////////////////////////////////////////////////////////////////////

#include "complex.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// Constructor IMPLEMENTATION
// Do NOT put the default values here!
Complex::Complex(double a, double b): re{a}, im{b} {
	// Empty -- the initializer list does everything
	// The pair of curly braces "{}" is necessary after
	// the initalizer list, in the IMPLEMENTATION file.
}

// Signature must match declaration PERFECTLY -- including const and &
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

bool operator==(const Complex &lhs, const Complex &rhs) {
    return (lhs.re == rhs.re && lhs.im == rhs.im);
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


