// FillInQ class implementation
#include "fillinq.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

FillInQ::FillInQ(const string& f) {
    ifstream file(f);
    getline(file, question_text);
    
    correct_answer = "";
    string combined_line;
    num_blanks = 0;

    while (getline(file, combined_line)) {
        if (combined_line.empty()) {
            continue; // Skip empty lines
        }
        
        if (!correct_answer.empty()) {
            correct_answer += " "; 
        }
        correct_answer += combined_line; 
        ++num_blanks;           
    }
}


void FillInQ::display() const{
    cout << question_text << endl;
    cout << "Fill in the blanks with the correct answers." << endl;
}

string FillInQ::accept_response() {
    string response;
    cout << "Your answer: ";
    getline(cin, response);
    return response;
}

bool FillInQ::execute() {
    display();
    string response = accept_response();
    return response == correct_answer;
}

void FillInQ::set_num_blanks(int n) {
    num_blanks = n;
}

int FillInQ::get_num_blanks() const {
    return num_blanks;
}
