// Problem 8
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class Waitlist {
private:
    std::vector<string> patients;
    int num_patients;
public:    
    Waitlist(): num_patients{0} {}  // The vector actually doesn't need to be initialized!
                                    // The default constructor for vectors creates an empty list.
    void add(string);
    string call();
};

void Waitlist::add(string n){
    patients.push_back(n);
    ++num_patients;
}

string Waitlist::call() {
    if (num_patients == 0) {
        return "";
    }
    string name = patients[0];          
    patients.erase(patients.begin());   
    --num_patients;
    return name;                        
}

int main() {
    Waitlist www;
    www.add("Evan");
    www.add("Frank");

    while (true){
        string call_name = www.call();
        if (call_name == "") {
            break;
        }
        cout << call_name << " ";
    }
}
