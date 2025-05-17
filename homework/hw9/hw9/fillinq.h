// FillInQ class header
#ifndef FILLINQ_H
#define FILLINQ_H

#include "question.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

class FillInQ : public Question {
protected:
    void display()const override;
    string accept_response() override;
private:
    int num_blanks;
public:
    FillInQ(const string&);
    bool execute();
    void set_num_blanks(int );
    int get_num_blanks() const;

};

#endif