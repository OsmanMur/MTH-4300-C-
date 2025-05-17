#include "rational.h"
#include <iostream>
#include <exception>

using std::cout; using std::cin; using std::endl; using std::string;

long long Rational::gcf() const {
    int x = std::abs(n);
    int y = std::abs(d);
    while (y != 0){
        int temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}

void Rational::reduce() {
    int g = gcf();
    n /= g;
    d /= g;
    if (d < 0) {
        n *= -1;
        d *= -1;
    }
}

Rational::Rational(int a, int b): n{a}, d{b} {
    if (b == 0) {
        throw std::domain_error("Divide by zero"); // Exception handling! We'll discuss later.
    }
    reduce();
} 
    
Rational Rational::operator+=(const Rational &rhs) {
    n = n*rhs.d + d*rhs.n;
    d = d*rhs.d;
    reduce();
    return *this;
}

Rational Rational::operator-=(const Rational &rhs) {
    n = n*rhs.d - d*rhs.n;
    d = d*rhs.d;
    reduce();
    return *this;
}

Rational Rational::operator*=(const Rational &rhs) {
    n *= rhs.n;
    d *= rhs.d;
    reduce();
    return *this;
}

Rational Rational::operator/=(const Rational &rhs) {
    if (rhs.n == 0) {
        throw std::domain_error("Divide by zero"); // Exception handling!
    }
    n *= rhs.d;
    d *= rhs.n;
    reduce();
    return *this;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational out = lhs; // Cheating!
    return out += rhs;  // Using += to implement +
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational out = lhs;
    return out -= rhs;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational out = lhs;
    return out *= rhs;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    Rational out = lhs;
    return out /= rhs;
}


bool operator==(const Rational &lhs, const Rational &rhs) {
    return lhs.n * rhs.d == rhs.n * lhs.d;
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational &lhs, const Rational &rhs) {
    int sign1 = 1, sign2 = 1;
    if (lhs.d < 0) {
        sign1 = -1;
    }
    if (rhs.d < 0) {
        sign2 = -1;
    } 
    return sign1 * rhs.d * sign2 * lhs.n <  lhs.d * sign1 * sign2 * rhs.n;
}

bool operator<=(const Rational &lhs, const Rational &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(const Rational &lhs, const Rational &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream &os, const Rational &rhs){
    os << rhs.n << " / " << rhs.d;
    return os;
}
    
std::istream& operator>>(std::istream &is, Rational &rhs){
    char slash;
    is >> rhs.n >> slash >> rhs.d;
    return is;
}