// Problem 9
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class ColVector; // This is necessary because each class has references to the other, so which one should be
                 // declared first??  This introduces the ColVector class, so that references to it
                 // within the Matrix class won't cause compilation errors.  (Alternative solution: make members public,
                 // and only introduce the operator* function as a non-friend, after both classes have been declared.)


class Matrix {
private:
    double a, b, c, d;
public:
    Matrix(double x, double y, double z, double w): a{x}, b{y}, c{z}, d{w} {}
    friend Matrix operator+(const Matrix&, const Matrix&);
    friend ColVector operator*(const Matrix&, const ColVector&);
};

Matrix operator+(const Matrix &m1, const Matrix &m2){
    return Matrix(m1.a+m2.a, m1.b+m2.b, m1.c+m2.c, m1.d+m2.d);
}

class ColVector {
private:
    double x, y;
public:
    ColVector(): x{0}, y{0} {}
    ColVector(double p, double q): x{p}, y{q} {}
    friend std::ostream& operator<<(std::ostream&, ColVector);
    friend ColVector operator*(const Matrix&, const ColVector&);
};

std::ostream& operator<<(std::ostream& os, ColVector v) {
    os << v.x << ", " << v.y;
    return os;
}

ColVector operator*(const Matrix &m, const ColVector&v) {
    return ColVector(m.a*v.x + m.b*v.y, m.c*v.x + m.d*v.y);
}


int main() {
	Matrix m1(1,2,3,4), m2(5, 4, 1, 10);
	ColVector v(10, 1);
	ColVector s;
	s = (m1 + m2) * v;
	cout << s;
}