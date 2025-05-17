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

using std::cout; using std::cin; using std::endl; using std::string;


class Fundraiser {														
public:																		
	string cause;
    double target;
    double current;
    
    void report();
    void donate(int);
    bool met();
    bool beats(Fundraiser);
};																			


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

    return 0;   
}

void Fundraiser::report() {
    cout << std::setprecision(2) << std::fixed;  // 2 points after the decimal.  Requires #include <iomanip>
    cout << "This Fundy is raising funds for:\n";
    cout << this->cause << endl;
    cout << "Amount raised: $" << this->current << "/$" << this->target << endl;
}

void Fundraiser::donate(int x) {
    (this->current) += x;
}

bool Fundraiser::met() {
    return (this->current) >= (this->target);
}

bool Fundraiser::beats(Fundraiser other) {
    return (this->current) > other.current;
}