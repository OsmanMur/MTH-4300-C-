////////////////////////////////////////////////////////////////////////////////
// hw4_q3.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

/* Prints out the contents of the array pointed to by `ptr`
   @param ptr     A ptr to an array of ints to be printed
   @param length  Length of the aforementioned array
   @precondition  `length` must be <= the length of `*ptr`
*/
void print(int *ptr, int length) {
    int *end = ptr + length;
    for (int *iter = ptr; iter != end; ++iter) {
        cout << *iter << " ";
    }
}

int main(){
    cout << "How many entries?";
    int num_entries;
    cin >> num_entries;
    int *arr;
    arr = new int[num_entries];

    for(int i = 0; i < num_entries; ++i) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    print(arr, num_entries);

    return 0;
}