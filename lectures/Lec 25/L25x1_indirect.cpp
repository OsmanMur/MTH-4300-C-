////////////////////////////////////////////////////////////////////////////////
// Indirect
// Showcasing indirect inheritance: Faculty and Staff inherit from Employee,
// which inherits from User.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

///////////////////TOP LAYER OF THE HIERARCHY///////////////////////////////////
class User {
protected: // with protected, derived classes can access these members
    int EMPLID;
    string first, last, email;
public:
    User(string, string, int);
    void display() const;
    void set_email(string);
};
///////////////////MIDDLE LAYER OF THE HIERARCHY////////////////////////////////
class Employee: public User {
protected:
    double pay_rate;
public:
    Employee(string, string, int, double);
    double pay(double) const;
    void display() const; 
    void set_email(string = ""); 
};

class Student: public User {
protected:
    std::vector<string> course_schedule;
public:
    Student(string, string, int);
    void add_class(string);
    void display() const;
};
///////////////////BOTTOM LAYER OF THE HIERARCHY////////////////////////////////
class Faculty: public Employee {
protected:
    std::vector<string> teaching_schedule;
    string department;
public:
    Faculty(string, string, int, double, string);
    void add_course(string);
    void display() const;
};

class Staff: public Employee {
protected:
    string role;
public:
    Staff(string, string, int, double, string); 
    void display() const;   
};
///////////////////main(), followed by some method implementations//////////////
int main() {
    Faculty ef("Evan", "Fink", 12345678, 1000000.0, "Math");
    ef.set_email();
    ef.display();
    ef.add_course("MTH 4300");
    return 0;
}


User::User(string f, string l, int emp): first{f}, last{l}, email{""}, EMPLID{emp} {
}
void User::display() const {  
    cout << "[User::display()]\n";
    cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;   
}
void User::set_email(string e) {  
    cout << "[User::set_email()]\n"; 
    email = e;
}

Employee::Employee(string f, string l, int emp, double r): User(f, l, emp), pay_rate{r} {
}
double Employee::pay(double hours) const {
    cout << "[Employee::pay()]\n";
    return pay_rate * hours;
} 
void Employee::display() const {
    cout << "[Employee::display()]\n";
    cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;    
    cout << "$" << pay_rate << " per hour" << endl;
}
void Employee::set_email(string e) {
    cout << "[Employee::set_email()]\n";
    if (e == "") {
        email = first + "." + last + "@baruch.cuny.edu";
    } else {
        email = e;
    }
}

Student::Student(string f, string l, int emp): User(f, l, emp) {
}
void Student::add_class(string c){
    cout << "[Student::add_class()]\n";
    course_schedule.push_back(c);
}
void Student::display() const{
    cout << "[Student::display()]\n";
    cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;  
    cout << "Courses: ";
    for (int i = 0; i < course_schedule.size(); ++i) {
        cout << course_schedule[i] << " ";
    }
    cout << endl;
}

Faculty::Faculty(string f, string l, int emp, double rate, string dpt): Employee(f, l, emp, rate), department{dpt} {
}
void Faculty::add_course(string c) {
    cout << "[Faculty::add_course()]\n";
    teaching_schedule.push_back(c);
}
void Faculty::display() const{
    cout << "[Faculty::display()]\n";
    cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;    
    cout << "$" << pay_rate << " per hour, Department of " << department << endl;
}

Staff::Staff(string f, string l, int emp, double rate, string r): Employee(f, l, emp, rate), role{r} {
}   
void Staff::display() const{
    cout << "[Staff::display()]\n";
    cout << EMPLID << ": " << last << ", " << first << endl << "Email: " << email << endl;    
    cout << "$" << pay_rate << " per hour, Role: " << role << endl;

} 

//direct inheritance --> means that the derived class inherits from the base class directly (how? = using the public keyword) which simply means that the derived class can access the public members of the base class
//indirect inheritance --> means that the derived class inherits from the base class indirectly (how? = using the protected keyword) which simply means that the derived class can access the protected members of the base class
