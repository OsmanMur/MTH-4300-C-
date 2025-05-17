////////////////////////////////////////////////////////////////////////////////
// Which
// When does operator= get called?  
// When does the copy constructor get called? 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class MyInt{
public:
    int num;
    
    MyInt(int x) { 
        cout << "INT CONSTRUCTOR" << endl; 
        num = x;
    }

    MyInt(const MyInt& rhs) {
        cout << "COPY CONSTRUCTOR" << endl;
        num = rhs.num;
    }
    //
    MyInt& operator=(const MyInt& rhs) {
        cout << "OPERATOR=" << endl;
        num = rhs.num;
        return *this;
    }

    ~MyInt(){
        cout << "DEST" << endl;
    }
};

////////////////////////////////////////////
int non_member_fn(MyInt q){
    cout << "The non-member function." << endl;
    return q.num;
}

int main() {
    MyInt one(5), two = 60;  // Two int constructors

    MyInt three(one);        // Copy constructor getting called 
    
    MyInt four = two;       // Copy constructor again, since `four` is being declared here.

    cout << "middle" << endl;

    two = one;              // Assignment operator -- there's no construction on this line.

    cout << non_member_fn(one);     // What is going on here?
                                    // Answer: because non_member_fn() takes its argument by value, not reference,
                                    // the first thing that happens in the function is a copy constructor call -- 
                                    // it copies the value of `one` into the parameter `q`.
    return 0;  
}