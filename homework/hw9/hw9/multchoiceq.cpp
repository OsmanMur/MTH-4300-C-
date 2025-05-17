// MultipleChoiceQ class implementation
#include "multchoiceq.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using std::cout; using std::cin; using std::endl; using std::string; using std::getline; using std::ifstream; using std::ofstream;

MultipleChoiceQ::MultipleChoiceQ(const string& f) {
    ifstream file(f);
    getline(file, question_text);

    string correct_index_str;
    getline(file, correct_index_str);
    int correct_index = std::stoi(correct_index_str);

    string line;
    while (getline(file, line)) {
        choices.push_back(line);
    }

    if (correct_index >= 1 && correct_index <= choices.size()) {
        correct_answer = choices[correct_index - 1];  
    }
}

void MultipleChoiceQ::display() const{
    cout << question_text << endl;
    for (int i = 0; i < choices.size(); ++i) {
        cout << i+1 << ") " << choices[i] << endl;
    }
}

string MultipleChoiceQ::accept_response() {
   int choice_num;
    cout << "Your answer: ";
    cin >> choice_num;

    if (choice_num >= 1 && choice_num <= choices.size()) {
        return choices[choice_num - 1]; 
    }

    return ""; 
}

bool MultipleChoiceQ::execute() {
    display();
    string response = accept_response();
    return response == correct_answer;
}
