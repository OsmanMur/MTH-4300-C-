////////////////////////////////////////////////////////////////////////////////
// Hiding
// Employee::display() HIDES the method User::display()
// However, the former can still be called.
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
    double pay_rate;
public:
    Employee(string, string, int, double);
    double pay(double) const;

    void display() const; // HIDES display() FROM BASE CLASS.
};

Employee::Employee(string f, string l, int emp, double r): User(f, l, emp), pay_rate{r} {
}                                                          
double Employee::pay(double hours) const {
    return pay_rate * hours;
}
// HIDING member function
void Employee::display() const {
    User::display();    // This is like just calling "display()", but the "User::" prefix specifies
                        // which version of display() is being called.
    cout << "$" << pay_rate << " per hour" << endl;
}


int main() {
    User a("Alice", "Adams", 87654321);
    a.set_email("alice.adams@baruch.cuny.edu");
    a.display();

    Employee x("Evan", "Fink", 12345678, 1000000.0);
    x.set_email("evan.fink@baruch.cuny.edu");
    x.display();
    return 0;
}

