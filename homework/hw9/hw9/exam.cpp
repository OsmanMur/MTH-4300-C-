// Exam class implementation
#include "exam.h"
#include "question.h"
#include "multchoiceq.h"
#include "shortansq.h"
#include "fillinq.h"
#include "shortansq.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

void Exam::add_q(Question* q) {
    question_list.push_back(q);
}

void Exam::run() {
    for (int i = 0; i < question_list.size(); ++i) {
        cout << "Question " << (i + 1) << ":" << endl;

        bool result = question_list[i]->execute();
        if (result) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect." << endl;
        }
        cout << endl;
    }
}




