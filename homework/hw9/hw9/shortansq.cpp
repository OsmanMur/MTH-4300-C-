// ShortAnsQ class implementation
#include "shortansq.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

ShortAnsQ::ShortAnsQ(const string& f) {
    ifstream file(f);
    getline(file, question_text);
    getline(file, correct_answer);
    
}

void ShortAnsQ::display() const {
    cout << question_text << endl;
}

string ShortAnsQ::accept_response() { 
    string response;
    cout << "Your answer: ";
    cin >> response;
    return response;
}


