// Question class header
#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string;

class Question {
protected:
    string question_text;
    string correct_answer;

    virtual void display() const;  
    virtual string accept_response();

public:
    Question(); 
    bool execute(); 

};

#endif // QUESTION_H 