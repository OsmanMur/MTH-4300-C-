////////////////////////////////////////////////////////////////////////////////
// hw3_q9.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

/* Alters arr by reversing the section between indexes between i and j, inclusive.
   @param arr        Array to be reserved
   @param i          Lower index of the range to be reversed
   @param j          Upper index of the range to be reversed
   @precondition     0 <= i < size of arr; same is true for j.
*/
void reverse_range(int arr[], int i, int j) {
    if (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        reverse_range(arr, i+1, j-1);
    }
}

int main() {
    int z[6] = {17, 29, 31, 14, 85, 60};
    reverse_range(z, 0, 5);
    for (int i = 0; i < 6; ++i) {
        cout << z[i] << " ";
    }
    cout << endl;
}