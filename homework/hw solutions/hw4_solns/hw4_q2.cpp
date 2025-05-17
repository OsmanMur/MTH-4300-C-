////////////////////////////////////////////////////////////////////////////////
// hw4_q2.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 


/* Returns whether or not a subset of entries from arr[i] to arr[j] sums to exactly val
   @param arr        An array of ints
   @param val        The target sum
   @param i          The lower index of the range where subset is sought
   @param j          The upper index of the range where subset is sought
   @precondition     0 <= `i` <= `j` <= the length of `arr`
   @returns          true if there exists a subset of `arr[i]` to `arr[j]` which sums to `val`, false otherwise
*/
bool subsum_help(int arr[], int val, int i, int j) {
    if (i > j) {      // Indexes are inverted: so there can only be the empty subset in this range, which would have sum 0
        return val == 0;
    } 
    // Either element arr[i] is not in a subset, in which case you need a subset of arr[i+1] to arr[j] which
    // sums to val; or arr[i] IS in the subset, in which case you need a subset of arr[i+1] to arr[j] which
    // sums to val-arr[i] 
    return subsum_help(arr, val, i + 1, j) || subsum_help(arr, val-arr[i], i + 1, j);
}


/* Returns whether or not a subset of arr[] sums to exactly val
   @param arr        An array of ints
   @param val        The target sum
   @param size       The number of elements in arr that we wish to examine
   @precondition     `size` <= the length of `arr`
   @returns          true if there exists a subset of `arr` which sums to `val`, false otherwise
*/
bool subsum(int arr[], int val, int size) {
    return subsum_help(arr, val, 0, size - 1);
}

int main(){
    int s[] = {16, 2, 4, 32, 1};
    // In the print out, you should see "1" for 0-7, 16-23, 32-39, 48-55
    for (int i = 0; i <= 65; ++i) {
        cout << i << ": " << subsum(s, i, 5) << endl;
    }
    return 0;
}