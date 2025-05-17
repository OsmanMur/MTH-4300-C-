////////////////////////////////////////////////////////////////////////////////
// Array
// Exploring the relations between pointers and arrays
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {
    int my_arr[4] = {120, 340, 560, 780};
    
    cout << "&my_arr[0] = " << &my_arr[0] << endl; // Notice the addresses
    cout << "&my_arr[1] = " << &my_arr[1] << endl; // all differ by 4
    cout << "&my_arr[2] = " << &my_arr[2] << endl; // 
    cout << "&my_arr[3] = " << &my_arr[3] << endl << endl;
    
    cout << "my_arr = " << my_arr << endl;
    cout << "my_arr + 2 = " << my_arr + 2 << endl; // Adding 2 to the address =
                                                   // the address 2 spaces down in the array
    
    // What will these lines print out?  * has higher precedence than +!
    cout << "*(my_arr + 1) = " << *(my_arr + 1) << endl;
    cout << "*my_arr + 1 = " << *my_arr + 1 << "\n----\n";   


    // What happens past i = 4?  Who knows?
    for (int i = 0; i <= 20; ++i) {
        cout << "my_arr[" << i << "] = " << my_arr[i] << endl; 
    }

    return 0;   
}
