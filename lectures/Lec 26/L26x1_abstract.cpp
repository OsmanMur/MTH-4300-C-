////////////////////////////////////////////////////////////////////////////////
// Abstract
// Because the User class really only exists to allow us to operate on
// all types of Users in a uniform manner, we decide to make this base 
// class abstract, by creating a pure virtual function.
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
    virtual void set_email(string);
    virtual void display() const = 0;  // MAKES THIS A PURE VIRTUAL METHOD AND THE CLASS AN ABSTRACT CLASS
                                      //This function is NOT implemented, 
                                     //and the class it is in not Instantiable (cannot create an object of this class)
};

class Employee: public User {
protected:
    double pay_rate;
public:
    Employee(string, string, int, double);
    double pay(double) const;
    void display() const override; 
    void set_email(string = "") override; 
};

class Student: public User {
protected:
    std::vector<string> course_schedule;
public:
    Student(string, string, int);
    void add_class(string);
    void display() const override;
};

class Faculty: public Employee {
protected:
    std::vector<string> teaching_schedule;
    string department;
public:
    Faculty(string, string, int, double, string);
    void add_course(string);
    void display() const override;
};

class Staff: public Employee {
protected:
    string role;
public:
    Staff(string, string, int, double, string); 
    void display() const override;   
};



int main() {
    // The code below exemplifies the power of having a base class, 
    // even if you don't instantiate it.  The existence of the base
    // User class means we can collect together the various classes.
    User* my_users[3];
    my_users[0] = new Faculty("Evan", "Fink", 12345678, 1000000.0, "Math"); // static is User, dynamic is Faculty
    my_users[1] = new Student("Johnny", "Student", 23456789); // static is User, dynamic is Student
    my_users[2] = new Staff("Jane", "Staffperson", 34567890, 345.00, "Head of HR"); // static is User, dynamic is Staff
    
    for(int i = 0; i < 3; ++i){
        my_users[i]->display(); 
    }

    ////////////////
    // Once `User` is turned into an abstract class,
    // the following line is NOT OK
    User x("Evan", "Fink", 12345678);

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