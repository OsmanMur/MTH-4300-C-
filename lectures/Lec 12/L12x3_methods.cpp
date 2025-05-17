////////////////////////////////////////////////////////////////////////////////
// Fundmeth
// Now, add methods: 
// .donate(): int as argument, add that int to current, return nothing
// .met(): no arguments, returns true if the current exceeds target
// .beats(): Fundraiser as argument, returns true if "your" current exceeds the 
//           "other" Fundraiser's current.  
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip> // For decimals
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


class Fundraiser {														
public:																		
	string cause;
    double target;
    double current;
    
    void report();
    
    // THREE METHOD PROTOTYPE 
    // DECLARATIONS: .donate(), .met() and .beats()


    void donate(double);

    bool met();

    bool beats(Fundraiser);
};																			

void Fundraiser::donate(double x) {
    this->current += x;
}

bool Fundraiser::met(){
    return (this->current) >= (this->target);
}

bool Fundraiser::beats(Fundraiser other){
    return (this->current) > other.current;
}



int main () {
    Fundraiser k;
    k.cause = "The poor Krakatoans!";
    k.target = 1000000;
    k.current = 0;

    k.report();
    k.donate(500);
    if (k.met()) {
        cout << "Hooray!";
    }    
    k.report();

    Fundraiser m;
    m.current = 0;

    cout << k.beats(m) << endl;

    return 0;   
}

void Fundraiser::report() {
    cout << std::setprecision(2) << std::fixed;  // 2 points after the decimal.  Requires #include <iomanip>
    cout << "This Fundy is raising funds for:\n";
    cout << cause << endl;
    cout << "Amount raised: $" << current << "/$" << target << endl;
}

// THREE METHOD DECLARATIONS
