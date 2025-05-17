// Question class implementation
#include "question.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string;


Question::Question() : question_text(""), correct_answer("") {} 

bool Question::execute() {
    display();
    string response = accept_response();
    return response == correct_answer;
}

void Question::display() const {
    cout << question_text << endl;          
}

string Question::accept_response() {
    string response;
    cout << "Your answer: ";
    cin >> response;
    return response;
}




