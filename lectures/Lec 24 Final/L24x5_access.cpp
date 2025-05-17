////////////////////////////////////////////////////////////////////////////////
// Access
// The following doesn't compile!
// HOWEVER, if you change the `private:` in `User` to `protected:`,
// it will compile, since the references within Employee to first, last, and
// email will be accessible now.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class User {
private:
    int EMPLID;                 
    string first, last, email;  // No longer public! Like raw data usually should be.
public:
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
    void display() const; 
    void set_email(string e = ""); 
};

Employee::Employee(string f, string l, int emp, double r): User(f, l, emp), pay_rate{r} {
}                                                          
double Employee::pay(double hours) const {
    return pay_rate * hours;
}
void Employee::display() const {
    User::display();    
    cout << "$" << pay_rate << " per hour" << endl;
}

// !!!!!!!!!!!!!!!
// With private `first`, `last`, `email`, this will be a problem....
void Employee::set_email(string e) {
    if (e == "") {
        email = first + "." + last + "@baruch.cuny.edu";
    } else {
        email = e;
    }
}
// HOWEVER: if we make them protected, then all will work.  
// Do that now!

int main() {
    Employee e("Evan", "Fink", 12345678, 1000000.0);
    e.set_email();
    e.display();
    return 0;
}

