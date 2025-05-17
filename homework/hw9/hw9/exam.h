// Exam class header
#ifndef EXAM_H
#define EXAM_H

#include "question.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

class Exam{
private:
    std::vector<Question*> question_list;
public:
    Exam() {}
    void add_q(Question*);
    void run();
    //void display();
    //string accept_response() ;
};
#endif