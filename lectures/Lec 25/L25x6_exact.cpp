////////////////////////////////////////////////////////////////////////////////
// Exact
// A caution about virtual functions: the signature of the derived class 
// function has to (usually) match the signature of the base class function 
// exactly: same numbers and type of arguments, same return types, same const!
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class User {
protected:
    int EMPLID;
    string first, last, email;
public:
    User(string f, string l, int emp): first{f}, last{l}, email{""}, EMPLID{emp} {
    }
    virtual void display() const {  
        cout << "[User::display()]\n";
        cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;   
    }
};

class Employee: public User {
protected:
    double pay_rate;
public:
    Employee(string f, string l, int emp, double r): User(f, l, emp), pay_rate{r} {
    }
    //
    // A trivial change: I've removed the "const" from display().
    // This seems like it ought to have no major effect -- but in fact,
    // it breaks the virtual inheritance.
    //
    void display() const override{
        cout << "[Employee::display()]\n";
        cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;    
        cout << "$" << pay_rate << " per hour" << endl;
    }
};



int main() {
    User* my_users[2];
    my_users[0] = new User("Evan", "Fink", 12345678);
    my_users[1] = new Employee("Johnny", "Employee", 23456789, 77.77);
    
    for(int i = 0; i < 2; ++i){
        my_users[i]->display(); 
    }

    return 0;
}