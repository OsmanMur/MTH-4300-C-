////////////////////////////////////////////////////////////////////////////////
// Constructdog
// Making two Dog constructors
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


class Dog {														
public:																		
	int age;
    double weight;
    string owner;
    
    //////////////// CONSTRUCTOR DECLARATIONS
    Dog();                      
    Dog(int, double, string);   

    int age_in_dog_years() const;       
    void bark_num_times(int) const;     
    void print_info() const; // An additional viewer method
};																			


int main () {
    Dog fido;                    // This calls DEFAULT constructor
    Dog rover(5, 10.5, "Evan");  // This calls three-parameter constructor

    fido.print_info();
    rover.print_info();
    return 0;     
}

////////////////// DEFAULT CONSTRUCTOR
Dog::Dog() {
    age = -1;
    weight = -1;
    owner = "Unknown";
}

////////////////// ANOTHER CONSTRUCTOR
Dog::Dog(int x, double y, string z) {
    age = x;
    weight = y;
    owner = z;
}

//// This is a method that returns the age in dog years.
int Dog::age_in_dog_years() const { 
    int answer = 7 * age; 
    return answer;
}
                                
void Dog::bark_num_times(int t) const {
    cout << owner << "'s dog says: "; 
    for (int i = 1; i <= t; ++i) {
        cout << "Bark";
    }
}

void Dog::print_info() const {
    cout << "Age: " << age << ", Weight: " << weight << ", Owner: " << owner << endl;
}







