// Problem 1
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	int h, m, s;
	char get_rid_of_stupid_colon;
	cin >> h >> get_rid_of_stupid_colon >> m >> get_rid_of_stupid_colon >> s;
	cout << h*3600 + m*60 + s << endl;
}
