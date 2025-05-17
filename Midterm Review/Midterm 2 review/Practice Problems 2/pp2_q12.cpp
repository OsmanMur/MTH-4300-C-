// Problem 12

/*
a. Since there is a non-default constructor, the compiler provides no default constructor.  Since there is no default constructor, 
two can't be declared without an int paramater.  This is a compilation error.

b. three.x and four.x will be inaccessible from main(), since x is a private member.  This will yield a compilation error.

c. When blah.same(blech) is called, the argument to the same() method is passed by VALUE.
The parameter `rhs` will therefore be constructed as a copy of `blech`, and rhs.y will be set to blech.y.
`rhs` is then destructed at the end of the same() method, and the destructor will call delete[] on rhs.y (which equals blech.y).
Then, when blech goes out of scope again at the end of main(), the destructor is called on blech, which will delete[] blech.y a SECOND time --
this is undefined behavior, and can cause a segmentation fault.  This would NOT give a compilation error.

d. q.entry(44) causes a compilation error, since q is a const object, and we call entry() on it, which is NOT a const method.
*/

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Something {
private:
	int x;
	string *y;
public:
	Something(int a): x{a}, y{new string[100]} {}
	~Something() {delete[] y;}
	void operator=(const Something &rhs){
	    x = rhs.x;
    }
	string entry(int n) {return y[n];}
	bool same (Something rhs) {
		for (int i = 0; i <= 99; ++i) {
			if (y[i] != rhs.y[i]) {
				return false;
			}
		}
		return true;
	}	 
};

///// Part a 
int main() {
	Something one(5), two;
	cout << one.entry(50) << endl;
	cout << two.entry(50) << endl;
}

/*
///// Part b
int main() {
	Something three(5);
	Something four(6);
	cout << three.x + four.x << endl;
}*/

/*
///// Part c
int main() {
	Something blah(20), blech(24);
	cout << blah.entry(5) << endl;
	cout << blah.same(blech) << endl;
}*/

/*
///// Part d
int main() {
	const Something q(5);
	Something z(10);
	z = q;	
	string w = q.entry(44);
	string j = z.entry(44);
}*/
