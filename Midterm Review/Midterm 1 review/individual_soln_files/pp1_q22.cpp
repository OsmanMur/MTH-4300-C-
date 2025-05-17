// Problem 22

/*
a. 102 304 hello w

b. Short answer, slightly less than fully precise answer: The value for y will definitely be 5.  Other than that, ????
More precise answer: In fact, x will have the value 0, and s will be the empty string.  On the other hand, c could truly contain
any character.

Input failure will generally assign a default value to the variable that is attempting to be assigned to -- this default value is 
0 for numerical types.  y, s, and c will retain their initialized values.   It is a fact that an uninitialized std::string will 
be assigned the empty string, but uninitialized chars will contain garbage.

c. x will get 12, y will get 34, s will get "hijk.", and then the program will hang, waiting for at least one more non-whitespace 
character to be entered so that c can get assigned.
*/

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int x = 23, y = 5;
	string s; 
	char c;
	cin >> x >> y >> s >> c;
	cout << x << " " << y << " " << s << " " << c;
}