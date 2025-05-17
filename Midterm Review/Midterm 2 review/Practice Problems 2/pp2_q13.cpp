// Problem 13
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

/* a. 
R1
R3
R3
Hello
~Des
Op=
~Des
~Des

b. The call to print() would not create a copy, so there would be no copy constructor call, and no argument destructor call.
R1
R3
Hello
Op=
~Des
~Des
*/

class Record {
public:
    string name;
    int id_num;
    Record(string n, int x): name{n}, id_num{x} {cout << "R1\n";}
    Record(string n): name{n}, id_num{0} {cout << "R2\n";}
    ~Record() {cout << "~Des\n";}
    Record(const Record &rhs) {
        cout << "R3\n";
        name = rhs.name;
        id_num = rhs.id_num;	
    }
    void operator=(const Record &rhs){
        cout << "Op=\n";
        name = rhs.name;
        id_num = rhs.id_num;
    }
};

// FOR PART B, PUT & IN FRONT OF ARG
void print(Record arg){
	cout << arg.name << endl;
}

int main(){
	Record x("Hello", 123);
	Record y = x;
	print(x);
	x = y;	
}