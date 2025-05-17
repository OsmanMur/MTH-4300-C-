////////////////////////////////////////////////////////////////////////////////
// Dog
// Who's a good class?  Who's a good class?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

class Dog{
    public:
        int age;
        double weight;
        string owner;

        int age_in_dog_years();
        void bark_num_times(int);
        
};

int Dog::age_in_dog_years(){
    int answer = 7 * (this->age);
    return age;
}

void Dog::bark_num_times(int times){
    for (int i = 0; i < times; ++i){
        cout << this->owner << "'s dog says : BARK" << endl;
    }
}

int main () {
    Dog rex;
    rex.age = 1;
    rex.weight = 5.5;
    rex.owner = "Osman";

    cout << rex.owner << "'s dog is " << rex.age << " years old";

    cout << rex.owner << "'s dog is " << rex.age_in_dog_years() << " in dog years old" << endl;

    rex.bark_num_times(10);

    return 0;   
}
