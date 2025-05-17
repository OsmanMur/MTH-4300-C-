////////////////////////////////////////////////////////////////////////////////
// list.cpp
// List class implementation
////////////////////////////////////////////////////////////////////////////////
#include "list.h"

//WILL BE AN EXAM TYPE OF QUESTION
void List::reserve() {
    if (capacity == 0) {
        listptr = new string[1]; // If the capacity is 0, doubling doesn't help!
        capacity = 1;            // So we simply make the length 1.
    }  else { 
        // Let's fill this in again.

        int new_capacity = capacity * 2;
        string *newptr = new string[new_capacity];
        for (int i = 0; i < capacity; ++i) {
            newptr[i] = listptr[i]; 
        }
        capacity = new_capacity; // Update the capacity
        delete[] listptr;
        listptr = newptr; // Update the pointer to point to the new array

        //BIG NO NO
        // listptr = newptr;
        // delete[] listptr;
       
    }
}

List::List(int n) {
    listptr = new string[n]; //pointer to the array
    capacity = n;
    num_entries = 0;
}

List::List() {
    listptr = nullptr;  // This is a special "null" address does not point to anything
    capacity = 0;  
    num_entries = 0;    
}

void List::append(const string &entry){
    if (num_entries >= capacity) {
        reserve();
    }
    listptr[num_entries] = entry; // breakdown: listptr is a pointer to an array of strings, num_entries is the index of the next available slot
    ++num_entries;
}

// Let's discuss this one.
string& List::operator[](int n) {
    return listptr[n];
}

List::~List() {
    delete[] listptr; // Deallocate the memory

    //WILL BE AN EXAM TYPE OF QUESTION
    cout <<"DESTRUCT";
}


void List::print() const {
    for(int idx = 0; idx < num_entries; ++idx) {
        cout << listptr[idx] << " ";
    }
    cout << endl;
}


List& List :: operator=(const list& rhs){
    if(&rhs == this) { // why? => to check if the object is assigned to itself
        return *this; // why? => to return the current object
    }
    
    capacity = rhs.capacity;
    num_entries = rhs.num_entries;
    delete[] listptr; // why? => to avoid memory leak
    listptr = new string[capacity]; // why? => to allocate new memory
    for (int i =0 ; i < num_entries; ++i) { // why? => to copy the elements into the new memory
        listptr[i] = rhs.listptr[i]; // why? => copy the elements
    }

    return *this; // why? => to return the current object
    //90 correct? doesnt work when x = x: object is assigned to itself.


}