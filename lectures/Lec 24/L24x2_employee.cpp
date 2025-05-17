////////////////////////////////////////////////////////////////////////////////
// Employee
// The Employee class is a derived class of the User class.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class User {
private:
    int EMPLID;
public:
    string first, last, email; 
    User(string, string, int);
    void display() const;
    void set_email(string);
};

User::User(string f, string l, int emp): first{f}, last{l}, email{""}, EMPLID{emp} {
}

void User::display() const {   
    cout << EMPLID << ": " << last << ", " << first << endl << email << endl;   
}
void User::set_email(string e) {   
    email = e;
}


// THE DERIVED CLASS
class Employee: public User {
private:
    double pay_rate;        // Attribute only for Employees
public:
    Employee(string, string, int, double);
    double pay(double) const;
};
                                                           // PAY ATTENTION HERE
Employee::Employee(string f, string l, int emp, double r): User(f, l, emp), pay_rate{r} {
}                                                          // Base class constructor call
                     
double Employee::pay(double hours) const {
    return pay_rate * hours;
}

int main() {
    Employee x("Evan", "Fink", 12345678, 1000000.0);

    cout << "x has a .first, which is public: " << x.first << endl;
    //cout << "x also has a .EMPLID, but that's private: " << x.EMPLID << endl;

    cout << "We can also call methods of the User class: " << endl;
    x.set_email("evan.fink@baruch.cuny.edu");
    x.display();
    return 0;
}

