// ShortAnsQ class header
#ifndef SHORTANSQ_H
#define SHORTANSQ_H

#include "question.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::getline;

class ShortAnsQ : public Question {
protected:
    void display() const override;
    string accept_response() override;
public:
    ShortAnsQ(const string& filename);
};


#endif