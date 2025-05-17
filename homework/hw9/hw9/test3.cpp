#include "multchoiceq.h"

int main() {
    MultipleChoiceQ q3("q3_mc.txt");
    if(q3.execute()) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect." << endl;
    }

    MultipleChoiceQ q5("q5_mc.txt");
    if(q5.execute()) {
        cout << "Correct!" << endl;
    } else {
        cout << "Fax Machines are not animals" << endl;
    }
    return 0;
}
