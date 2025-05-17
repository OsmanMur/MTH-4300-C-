#include "fillinq.h"

int main() {
    FillInQ q2("q2_fitb.txt");
    if(q2.execute()) {
        cout << "Correct!" << endl;
    } else {
        cout << "You've let me down with your incorrect answer." << endl;
    }

    FillInQ q4("q4_fitb.txt");
    if(q4.execute()) {
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

