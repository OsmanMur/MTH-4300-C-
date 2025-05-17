////////////////////////////////////////////////////////////////////////////////
// rational.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "rational.h"
using std::cout; using std::cin; using std::endl; using std::string;

Rational::Rational(long long a, long long b): num{a}, den{b}{
    reduce();
}

long long Rational::gcf(long long a, long long b){
    long long x = a;
    long long y = b;

    while (y!=0) {
        long long temp = y;
        y = x % y;
        x = temp;
    }
        return x;
}

void Rational::reduce(){
    long long g = gcf(num, den);
    num /= g;
    den /= g;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}


Rational operator+(const Rational& a, const Rational& b) {
    Rational result = a;
    result += b;
    return result;
}

Rational operator-(const Rational& a, const Rational& b) {
    Rational result = a;
    result -= b;
    return result;
}

Rational operator*(const Rational& a, const Rational& b) {
    Rational result = a;
    result *= b;
    return result;
}

Rational operator/(const Rational& a, const Rational& b) {
    Rational result = a;
    result /= b;
    return result;
}


Rational& Rational::operator+=(const Rational& rhs) {
    num = num * rhs.den + rhs.num * den;
    den = den * rhs.den;
    reduce();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
    num = num * rhs.den - rhs.num * den;
    den = den * rhs.den;
    reduce();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    num = num * rhs.num;
    den = den * rhs.den;
    reduce();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    num = num * rhs.den;
    den = den * rhs.num;
    reduce();
    return *this;
}



bool operator==(const Rational& a, const Rational& b){
    return (a.num == b.num && a.den == b.den);
}

bool operator!=(const Rational& a, const Rational& b){
    return !(a == b);
}

bool operator<(const Rational& a, const Rational& b){
    return (a.num * b.den < b.num * a.den);
}

bool operator<=(const Rational& a, const Rational& b){
    return (a.num * b.den <= b.num * a.den);
}

bool operator>(const Rational& a, const Rational& b){
    return (a.num * b.den > b.num * a.den);
}

bool operator>=(const Rational& a, const Rational& b){
    return (a.num * b.den >= b.num * a.den);
}

std::ostream& operator<<(std::ostream& os, const Rational& r){
    os << r.num << " / " << r.den;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r){
    char c;
    is >> r.num >> c >> r.den;
    r.reduce();
    return is;
}


