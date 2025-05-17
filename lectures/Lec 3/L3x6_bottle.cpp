////////////////////////////////////////////////////////////////////////////////
// Bottle
// 99 bottles of beer on the wall, 99 bottles of beer...
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	//if a body is a single line brackets are optional for/while/ others but NOT a good habit
	for (int i=99; i>0; --i){
		cout << i << " bottles of beer on the wall, " << i << " bottles of beer\n";
		cout << "If one of those bottles should happen to fall, " << i-1 << " bottles of beer on the wall\n";

	}

	
	return 0;
}