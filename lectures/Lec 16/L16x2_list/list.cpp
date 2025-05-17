////////////////////////////////////////////////////////////////////////////////
// list.cpp
// List class implementation
////////////////////////////////////////////////////////////////////////////////
#include "list.h"

List::List(int n) {
    listptr = new string[n];//what does 'new' do? --> It allocates memory on the heap. It returns the address of the first byte of the memory block.
    capacity = n;
    num_entries = 0;
}

List::List() {

   //listptr = nullptr;  // This is a special "null" address no memory is allocated.
   listptr = new string[1];
    capacity = 0;  
    num_entries = 0;    
}

void List :: append(const string &str){
    if(num_entries == capacity){
        reserve(); // What does this line do? --> It checks if the list is full and if it is, it calls the reserve function to allocate more memory.
    }

    listptr[num_entries] = str; //  What does this line do? --> It assigns the string to the next available spot in the list.
    ++num_entries; // What does this line do? --> It increments the number of entries in the list.
}

void List::reserve(){
    int newcap = 2*capacity;
    string* newptr = new string[newcap]; // What does this line do? --> It allocates a new block of memory that is twice the size of the current block.
    for (int idx =0; idx < capacity; ++idx){ // What does this line do? --> copies  from listptr to newpointer.
        newptr[idx] = listptr[idx]; //newptr shuold be on the left side!
    }
    capacity = newcap;// variable storing capacity is updated 
    delete[] listptr; // release old memory
    listptr = newptr; // set variable pointer to new update list ptr
}

void List::print() const {
    for(int idx = 0; idx < num_entries; ++idx) {
        cout << listptr[idx] << " ";
    }
    cout << endl;
}
