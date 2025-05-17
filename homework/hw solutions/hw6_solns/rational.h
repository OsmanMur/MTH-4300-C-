#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <exception>

using std::cout; using std::cin; using std::endl; using std::string;

class Rational {
private:
    long long n;
    long long d;
    long long gcf() const;
public:
    Rational(int = 0, int = 1);
    void reduce();
    Rational operator+=(const Rational&);
    Rational operator-=(const Rational&);
    Rational operator*=(const Rational&);
    Rational operator/=(const Rational&);
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);

    friend bool operator==(const Rational&, const Rational&);
    friend bool operator!=(const Rational&, const Rational&);
    friend bool operator<=(const Rational&, const Rational&);
    friend bool operator>=(const Rational&, const Rational&);
    friend bool operator<(const Rational&, const Rational&);
    friend bool operator>(const Rational&, const Rational&);

    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);
};

# endif