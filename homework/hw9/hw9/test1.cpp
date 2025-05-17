#include "shortansq.h"

int main() {
    ShortAnsQ q("q1_sa.txt");
    if(q.execute()) {
        cout << "Correct!" << endl;
    } else {
        cout << "Hmmm...check your addition." << endl;
    }
    return 0;
}

