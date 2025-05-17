#include "fillinq.h"
#include "exam.h"
#include "multchoiceq.h"
#include "question.h"
#include "shortansq.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // // Process the Rick Astley question
    // FillInQ q1("q2_fitb.txt");
    // bool result1 = q1.execute();
    
    // if (result1) {
    //     cout << "That's correct! You know your Rick Astley lyrics!" << endl;
    // } else {
    //     cout << "You've let me down with your incorrect answer." << endl;
    // }
    
    // // Process the Spanish numbers question
    // FillInQ q2("q4_fitb.txt");
    // bool result2 = q2.execute();
    
    // if (result2) {
    //     cout << "Correct! You know your Spanish numbers!" << endl;
    // } else {
    //     cout << "Sorry, that's not correct." << endl;
    // }

    // ShortAnsQ q3("q1_sa.txt");
    // bool result3 = q3.execute();

    // if (result3) {
    //     cout << "Correct!" << endl;
    // } else {
    //     cout << "Sorry, that's not correct." << endl;
    // }
    

    // MultipleChoiceQ q4("q3_mc.txt");
    // bool result4 = q4.execute();

    // if (result4) {
    //     cout << "Correct!" << endl;
    // } else {
    //     cout << "Sorry, that's not correct." << endl;
    // }

    // MultipleChoiceQ q5("q5_mc.txt");
    // bool result5= q5.execute();

    // if (result5) {
    //      cout << "Correct!" << endl;
    //  } else {
    //     cout << "Sorry, that's not correct." << endl;
    // }
    

    FillInQ q1("q2_fitb.txt");
    FillInQ q2("q4_fitb.txt");
    ShortAnsQ q3("q1_sa.txt");
    MultipleChoiceQ q4("q3_mc.txt");
    MultipleChoiceQ q5("q5_mc.txt");

    Exam exam;
    exam.add_q(&q1);
    exam.add_q(&q2);
    exam.add_q(&q3);
    exam.add_q(&q4);
    exam.add_q(&q5);

    exam.run();

    return 0;
}
