////////////////////////////////////////////////////////////////////////////////
// rational.h
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Rational{

private:
    long long num;
    long long den;

    long long gcf(long long , long long);


public: 
    Rational(long long = 0, long long = 1); // Default constructor
    void reduce();

    // Arithmetic operators
    //note: these are not member functions, but rather friend functions
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);

    // note: these are member functions? why? --> because they are unary operators. unary means they only take one operand. operand means the thing that the operator is applied to. for example, in the expression -x, x is the operand and - is the operator. so unary operators only take one operand. binary operators take two operands. for example, in the expression x + y, x and y are the operands and + is the operator. so unary operators are member functions because they only take one operand, which is the object itself. binary operators can be either friend functions or member functions depending on whether you want to allow the left operand to be of a different type.
    Rational& operator+=(const Rational&);
    Rational& operator-=(const Rational&);
    Rational& operator*=(const Rational&);
    Rational& operator/=(const Rational&);
        
    //when do I use frend vs. member functions? -->
    // 1. If the function needs to access private data members of the class, it should be a member function.
    // 2. If the function is a binary operator and you want to allow the left operand to be of a different type, it should be a friend function.
    // 3. If the function is a unary operator, it should be a member function.


    friend bool operator==(const Rational&, const Rational&); //this is a d
    friend bool operator!=(const Rational&, const Rational&);
    friend bool operator<(const Rational&, const Rational&);
    friend bool operator<=(const Rational&, const Rational&);
    friend bool operator>(const Rational&, const Rational&);
    friend bool operator>=(const Rational&, const Rational&);


    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

};


# endif