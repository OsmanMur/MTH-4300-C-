// Problem 10
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class Fakedex {
private:
    int capacity; // Number of Fakemon currently capable of being stored
    string *names;
    bool *have; 
    void reserve(int); // Should change `capacity` and the lengths of arrays pointed to by `names` and `have`
	                      // so that the all are equal to the argument 

public:
    Fakedex(): capacity{100}, names{new string[100]}, have{new bool[100]} {}
    void new_name(int, string); // Introduces a new name into `*names` at a given index,
                                // sets corresponding entry in `*have` to be `false`
    void catch_em(string);      // Set corresponding index in `*have` to `True`,
                                // if the parameter is present in `*names`
    bool operator[](string);    // If the parameter is in `*names`, return the corresponding value of `*have`,
                                // otherwise return `false`
	  
                           
    ~Fakedex() {delete[] names; delete[] have;}

    //////////// Part of answer to Part E: 
    // Rule of 3!!!  Since there is a destructor, there should be:
    Fakedex(const Fakedex&);                        // -Copy constructor
    Fakedex& operator=(const Fakedex&);             // -Copy assignment
    

    //////////// Not part of the problem, but present for testing
    void print() const;
};


//////////// Part a
void Fakedex::reserve(int n){
    if (n > capacity) {
        string *tempnames = new string[n];
        bool *temphave = new bool[n];
        for (int i = 0; i < capacity; ++i) {
            tempnames[i] = names[i];
            temphave[i] = have[i];
        }
        delete[] names;
        delete[] have;
        names = tempnames;
        have = temphave;
        capacity = n;
    }
}

//////////// Part b
void Fakedex::new_name(int x, string y){
    if (x >= capacity) {
        reserve(x+1);
    }
    names[x] = y;
    have[x] = false;
}

//////////// Part c
void Fakedex::catch_em(string y){
    for(int i = 0; i < capacity; ++i) {
        if (names[i] == y) {
            have[i] = true;
            return;
        }
    }
}

//////////// Part d
bool Fakedex::operator[](string s){
    for(int i = 0; i < capacity; ++i) {
        if (names[i] == s) {
            return have[i];
        }
    }
    return false;
}

//////////// The rest of the answer to Part E
Fakedex& Fakedex::operator=(const Fakedex &rhs){
    if (this == &rhs) {
        return *this;
    }
    capacity = rhs.capacity;
    delete[] names;
    delete[] have;
    names = new string[capacity];
    have = new bool[capacity];
    for (int i = 0; i < capacity; ++i) {
        names[i] = rhs.names[i];
        have[i] = rhs.have[i];
    }
    return *this;
}

Fakedex::Fakedex(const Fakedex &rhs){
    capacity = rhs.capacity;
    names = new string[capacity];
    have = new bool[capacity];
    for (int i = 0; i < rhs.capacity; ++i) {
        names[i] = rhs.names[i];
        have[i] = rhs.have[i];
    }
}



//////////// All below is not part of the problem, but present for testing
void Fakedex::print() const{
    for (int idx = 0; idx < capacity; ++idx) {
        cout << idx << ": " << names[idx] << " -->";
        if (!have[idx]) {
            cout << " not";
        } 
        cout << " found\n";
    }
}



int main() {
    Fakedex x, y;
    x.new_name(5, "Bluhbluh");
    x.new_name(0, "Fikachu");
    x.new_name(57, "Snurpdup");
    x.catch_em("Bluhbluh");
    cout << "x[\"Bluhbluh\"]: " << x["Bluhbluh"] << endl;
    y = x;
    y.print();
    return 0;
}