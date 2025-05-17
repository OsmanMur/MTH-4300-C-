////////////////////////////////////////////////////////////////////////////////
// Dog
// Who's a good class?  Who's a good class?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Dog {														
public:																		
    int age;
    double weight;
    string owner;
    int age_in_dog_years();
    void bark_num_times(int); 
};	

int main () {
    Dog fido;
    fido.age = 20;
    fido.weight = 17.2;
    fido.owner = "Evan";

    cout << fido.age_in_dog_years() << endl;
    fido.bark_num_times(4);

    return 0;     
}

int Dog::age_in_dog_years() {
    int answer = 7 * (this->age);
    return answer;
}

void Dog::bark_num_times(int t) {  
    cout << this->owner << "'s dog says: ";
    for (int i = 1; i <= t; ++i) {
        cout << "Bark";
    }
}