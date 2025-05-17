////////////////////////////////////////////////////////////////////////////////
// hw4_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: SOLUTIONS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;


#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main(){
    string *arr = new string[5];
    int arr_length = 5, index = -1;

    do{
        ++index;
        if (index >= arr_length) {
            // Allocate the new array
            string *temp = new string[arr_length*2];

            // Copy the contents of the old array into the first half of the new array.
            for (int i = 0; i <= arr_length - 1; ++i){
                temp[i] = arr[i];
            }

            // Now that the new array has been allocated and filled, delete the old array.
            delete[] arr;

            // Update the arr pointer AND the variable holding the current length of the array
            arr = temp;
            arr_length *= 2;
        }
        cin >> arr[index];   
    } while (arr[index] != "STOP");


    // FOR CHECKING
    for(int i = 0; i < arr_length; ++i) {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    // and i guess you should also
    delete[] arr; // at the end


    return 0;
}