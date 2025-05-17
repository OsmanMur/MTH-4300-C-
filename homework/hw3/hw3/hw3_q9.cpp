////////////////////////////////////////////////////////////////////////////////
// hw3_q9.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: Osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Reverses a portion of an array in place within a specified range
   @param arr   An array of integers to be modified
   @param i     The starting index of the range to reverse
   @param j     The final index of the range to reverse
   @precondition   0 <= i <= j < length of arr
   Updates the elements in arr from index i to j in reversed order
*/


// WRITE YOUR RECURSIVE FUNCTION `reverse_range()` HERE.
void reverse_range(int arr[], int i, int j){

    if (i < j){ // base case
        
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        reverse_range(arr, i+1, j-1);
    }
    
}




int main() {
    int z[6] = {17, 29, 31, 14, 85, 60};

    reverse_range(z, 1, 4);

    for (int i = 0; i < 6; ++i) {
        cout << z[i] << " ";
    }

    cout << endl;
}