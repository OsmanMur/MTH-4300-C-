////////////////////////////////////////////////////////////////////////////////
// Dynamic
// A dynamically-declared array, with run-time size!
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; 

int main () {  
    cout << "How many ints do you want in your array? ";
    int size;
    cin >> size;
    
    // REMINDER: THE FOLLOWING IS ILLEGAL
    //
    // int illegal_array[size];

    int *dynArray; // This can be a pointer to an int or an array of ints.
    
    // We allocate the array dynamically ("heap-allocate") because we don't know the size at compile-time.
	dynArray = new int[size];	
    
    // Writing and reading our array.
    for(int i = 0; i < size; ++i) {		
        dynArray[i] = i;    				
    }                				
    cout << "Here are the entries: " << endl;		
    for(int i=0; i < size; ++i) {		
        cout << dynArray[i] << endl;		// Remember: dynArray[i] is the same as *(dynArray + i)
    }										
	
	return 0;   
}
