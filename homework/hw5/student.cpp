////////////////////////////////////////////////////////////////////////////////
// student.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

// CLASS DEFINITION HERE
class Student {
    public:
    string name;
    int num_submitted;
    int scores[10];

    Student();                            
    Student(string);     

    void add_score(int);                 
    double average() const;
    void display() const;
};
//

int main() {
    Student x;
    Student y("Evan");

    x.display();  // Should display "Name: ?, Average: 0"

    y.add_score(3);
    y.add_score(4);
    y.add_score(6);
    y.display();  // Should display "Name: Evan, Average: 4.33333"

    for(int i = 1; i <= 20; ++i){
        // Even though I attempt to add twenty scores of 1, only the first seven should get recorded.
        // The last thirteen should silently be discarded.
        y.add_score(1);
    }
    y.display(); // Should display "Name: Evan, Average: 2" (exactly 2!)

    return 0;
}

//
// MEMBER FUNCTION IMPLEMENTATIONS HERE 
// 
Student::Student() {
    name = "?";
    num_submitted = 0;
}

Student::Student(string n) {
    name = n;
    num_submitted = 0;
}

void Student::add_score(int score) {
    if (num_submitted < 10) {
        scores[num_submitted] = score;
        ++num_submitted;
    }
}

double Student::average() const {
    if (num_submitted == 0) 
        return 0;
    int total = 0;
    for (int i = 0; i < num_submitted; ++i) {
        total += scores[i];
    }
   
    return static_cast<double>(total) / num_submitted;
}

void Student::display() const {
    cout <<" Name: "<< name << ", Average: " << average() << endl;
}