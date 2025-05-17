////////////////////////////////////////////////////////////////////////////////
// hw4_q1.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

/* Counts the number of partitions of an integer N into the sums of positive integers which are all <= `top`
   @param N        Integer to be partitioned
   @param top      The highest integer that can be used in a partition
   @precondition   N > 0     
   @returns        Number of partitions of N with all elements <= `top`
*/

int part_help(int N, int top) {
    if (N < 0) {
        return 0;
    } else if (top == 1) {
        return 1;
    }
    return part_help(N-top, top) + part_help(N, top - 1);
}


/* Counts the number of partitions of an integer N into the sums of positive integers
   @param N        Integer to be partitioned
   @precondition   N > 0     
   @returns        Number of partitions of N
*/
int part(int N) {
    return part_help(N, N);
}



int main(){
    cout << "part(5) = "  << part(5) << " (should be 7)" << endl;
    cout << "part(10) = "  << part(10) << " (should be 42)" << endl;
    cout << "part(50) = "  << part(50) << " (should be 204226)" << endl;
    
    return 0;
}