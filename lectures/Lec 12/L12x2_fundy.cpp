////////////////////////////////////////////////////////////////////////////////
// Fundy
// Create the definition of a class called `Fundraiser`.
// Fundraiser objects should each have three member variables:
// * the `cause` for the fundraiser (i.e., a message describing what the fundraiser is for)
// * the `target` value for the fundraiser, in dollars 
// * the `current` amount raised.
// Then, in `main()`, create one Fundraiser object, for a million dollar fundraiser
// for the victims of the Krakatoa volcano.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;


// CREATE Fundraiser CLASS WITH `cause`, `target`, AND `current` MEMBER VARIABLES
class fundraiser{
    public:
        string cause;
        double target;
        double current;
        
        
};

int main () {
    // CREATE A Fundraiser OBJECT, AND SET MEMBERS
    fundraiser yolo;
    yolo.cause = "you only live once";
    yolo.target = 1000000;
    yolo.current = 0;

    cout << "The fundraiser is for " << yolo.cause << " and has a target of $" << yolo.target << " and has raised $" << yolo.current;
    return 0;   
}
