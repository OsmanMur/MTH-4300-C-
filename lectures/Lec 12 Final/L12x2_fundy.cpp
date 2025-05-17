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

class Fundraiser {														
public:																		
	string cause;
    double target;
    double current;
};																			

int main () {
    Fundraiser k;
    k.cause = "The poor Krakatoans!";
    k.target = 1000000;
    k.current = 0;

    return 0;   
}

