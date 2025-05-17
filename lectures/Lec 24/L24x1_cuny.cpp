////////////////////////////////////////////////////////////////////////////////
// CUNY
// An awkward start at a system
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class Faculty {
private:
    int EMPLID;
    double pay_rate;
    std::vector<string> teaching_schedule;
    string email;
public:
    string first, last;
    Faculty(string f, string l, int emp, double pr): first{f}, last{l}, EMPLID{emp}, pay_rate{pr} {}
    double get_pay(double hours) const { return hours*pay_rate; } 
    double add_course(string &course) {teaching_schedule.push_back(course);}
    void display() const{
        cout << first << " " << last << " " << email << endl;
    }
};

class Student {
private:
    int EMPLID;
    std::vector<string> class_schedule;
    string email;
public:
    string first, last;
    Student(string f, string l, int emp): first{f}, last{l}, EMPLID{emp} {}
    double enroll_course(string &course) {class_schedule.push_back(course);}
    void display() const{
        cout << first << " " << last << " " << email << endl;
        for (auto &i =  class_scedule.begin(); i != class_schedule.end(); ++i) {
            cout << *i << " ";
        }
    }
};

class Staff {
private:
    int EMPLID;
    double pay_rate;
    string email;
public:
    string first, last, role;
    Staff(string f, string l, int emp, double pr, string r): first{f}, last{l}, EMPLID{emp}, pay_rate{pr}, role{r} {}
    double get_pay(double hours) const { return hours*pay_rate; } 
};


int main() {
    Faculty me("Evan", "Fink", 12345678, 100000.00);
    Student j("John", "Doe", 23456789);
    Staff s("Staffy", "Staffman", 34567890, 123.00, "Head of HR");
    return 0;  
}