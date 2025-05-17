////////////////////////////////////////////////////////////////////////////////
// syngrouptest.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;

std::random_device ran_dev;          
std::mt19937 gen(ran_dev());      


// CLASS DECLARATION AND DEFINITION HERE!
class SynGroup {
    private:
        string words[20];
        int length;
    
    public:
        SynGroup();                                 
        SynGroup(string);             
        bool has_word(string);        
        string replacement(string) ; 
        void display() ;                      
    };
    
int main() {
    SynGroup sg1("bus.txt");
    cout << "The following should display 10 phrases, starting with \"bus\" and ending with \"passenger vehicle\"" << endl;
    sg1.display();

    if (sg1.has_word("jitney") && sg1.has_word("passenger vehicle") && !sg1.has_word("marshmellow")) {
        cout << "has_word() test passed" << endl;
    } else {
        cout << "has_word() test failed" << endl;
    }
      
    SynGroup sg2("bill.txt");
    cout << "\n\nThe following 10 lines should contain both \"bill\" and \"invoice\", randomly, and ONLY those words:\n";
    for (int i = 1; i <= 10; ++i){
        cout << sg2.replacement("account") << endl;
    }

    cout << "\n\nThe next SynGroup should not be successfully created." << endl;
    SynGroup fail("thisfiledoesntexist.txt");
    return 0;
}

// MEMBER FUNCTION IMPLEMENTATIONS HERE

SynGroup::SynGroup() {
    length = 0;
}

SynGroup::SynGroup(string filename) {
    std::ifstream file(filename);
    length = 0;

    if (!file) {
        std::cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line) && length < 20) {
        words[length] = line;
        ++length;
    }

    file.close();
}

bool SynGroup::has_word(string w) {
    for (int i = 0; i < length; ++i) {
        if (words[i] == w)
            return true;
    }
    return false;
}

string SynGroup::replacement(string w) {
    if (!has_word(w)) 
        return w;

   std::uniform_int_distribution<> distr(0, length-1);
   int rand_index = distr(gen);

   string s = w;
   while (s == w) {
       int rand_index = distr(gen);
       s = words[rand_index];
   }

   return s;
}

void SynGroup::display() {
    for (int i = 0; i < length; ++i) {
        cout << words[i] << endl;
    }
}