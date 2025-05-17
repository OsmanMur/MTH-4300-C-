////////////////////////////////////////////////////////////////////////////////
// Leak
// Memory Leak! We greedily request memory frequently, and never deallocate.
// What happens?  Who knows?
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
    int MILLION = 1000000, FIFTY_THOU = 50000;
    
    cout << "Start" << endl;
    
    for(int i = 1; i <= FIFTY_THOU; ++i) {
        int *x = new int[MILLION];  
        cout << x << endl; //since array is saved to
		//delete[] x; // COMMENT THIS OUT FOR CHAOS
                    
        // 50,000 * 1,000,000 * 4  = 200 billion bytes would be requested.
    }
    
    cout << "Done" << endl;
    return 0;
}
