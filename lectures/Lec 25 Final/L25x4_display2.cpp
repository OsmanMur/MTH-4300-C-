////////////////////////////////////////////////////////////////////////////////
// Display2
// We wish to be able to write code which can handle all the different
// Display sub-types with the same code.  But it doesn't quite work...
// ...until we make a method virtual.
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
    User(string, string, int);
    ///////// CHANGE
    // Place `virtual` in front of `void` on the next line.
    virtual void display() const;
    void set_email(string);
};
class Employee: public User {
protected:
    double pay_rate;
public:
    Employee(string, string, int, double);
    double pay(double) const;
    ///////// CHANGE
    // Place `override` at the end of the next line
    void display() const override; 
    void set_email(string = ""); 
};
class Student: public User {
protected:
    std::vector<string> course_schedule;
public:
    Student(string, string, int);
    void add_class(string);
    ///////// CHANGE
    // Place `override` at the end of the next line
    void display() const override;
};
class Faculty: public Employee {
protected:
    std::vector<string> teaching_schedule;
    string department;
public:
    Faculty(string, string, int, double, string);
    void add_course(string);
    ///////// CHANGE
    // Place `override` at the end of the next line
    void display() const override;
};
class Staff: public Employee {
protected:
    string role;
public:
    Staff(string, string, int, double, string); 
    ///////// CHANGE
    // Place `override` at the end of the next line
    void display() const override;   
};



int main() {
    User* my_users[3];
    my_users[0] = new Faculty("Evan", "Fink", 12345678, 1000000.0, "Math");
    my_users[1] = new Student("Johnny", "Student", 23456789);
    
    // The point of this paragraph of silly code is:
    //      With an array of pointers, it is 
    //      entirely possible to NOT KNOW the
    //      type of the referenced object at COMPILE time.
    cout << "Is Jane Staffpersion a Faculty member or Staff member? ";
    string response;
    cin >> response;
    if (response == "Faculty") {
        my_users[2] = new Faculty("Jane", "Staffperson", 34567890, 345.00, "Dept");
    } else {
        my_users[2] = new Staff("Jane", "Staffperson", 34567890, 345.00, "Head of HR");
    }

    for(int i = 0; i < 3; ++i){
        my_users[i]->display(); 
    }

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