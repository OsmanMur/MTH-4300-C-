// MultipleChoiceQ class implementation
#ifndef MCQ_H
#define MCQ_H

#include "question.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

class MultipleChoiceQ : public Question {
protected:
    void display() const override;
    string accept_response() override;   
private:
    std::vector <string> choices;
public:
    MultipleChoiceQ(const string&);
    bool execute();
};


#endif