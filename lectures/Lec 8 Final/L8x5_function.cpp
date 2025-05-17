////////////////////////////////////////////////////////////////////////////////
// Function
// Pointers and arrays are interchangeable in many ways, including as arguments.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; 

/* Adds 2 to each entry in *arr
*/
void add2(int *arr, int length) {
    int *end = arr + length;  // A pointer to one-past the end of the array.

    // item is a pointer that goes from the address of the first element of `arr` to the last.
    // ++item moves item one ENTRY forward.
    for(int *item = arr; item != end; ++item) {  
        *item += 2;   // *item is the actual entry.
    }
}

int main() {
	int values[] = {14, 25, 36};
    add2(values, 3);  // This function takes the array, and adds 2 to each element.

    for(int *item = values; item < values + 3; ++item){
        cout << *item << endl;
    }
    return 0;
}