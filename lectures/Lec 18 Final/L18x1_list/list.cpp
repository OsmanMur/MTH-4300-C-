////////////////////////////////////////////////////////////////////////////////
// list.cpp
// List class implementation
////////////////////////////////////////////////////////////////////////////////
#include "list.h"

void List::reserve() {
    if (capacity == 0) {
        listptr = new string[1]; // If the capacity is 0, doubling doesn't help!
        capacity = 1;            // So we simply make the length 1.
    }  else { 
        string *temp = new string[2*capacity];
        for (int idx = 0; idx < num_entries; ++idx){
            temp[idx] = listptr[idx];
        }
        delete[] listptr;
        listptr = temp;
        capacity *= 2;
    }
}

List::List(int n) {
    listptr = new string[n];
    capacity = n;
    num_entries = 0;
}

List::List() {
    listptr = nullptr;  // This is a special "null" address
    capacity = 0;  
    num_entries = 0;    
}

// COPY CONSTRUCTOR
List::List(const List& rhs) {
    capacity = rhs.capacity;
    num_entries = rhs.num_entries;
    listptr = new string[capacity];
    for(int i = 0; i < num_entries; ++i){
        listptr[i] = rhs.listptr[i];
    }
}


void List::append(const string &entry){
    if (num_entries >= capacity) {
        reserve();
    }
    listptr[num_entries] = entry;
    ++num_entries;
}

// Let's discuss this one.
string& List::operator[](int n) {
    return listptr[n];
}

void List::print() const {
    for(int idx = 0; idx < num_entries; ++idx) {
        cout << listptr[idx] << " ";
    }
    cout << endl;
}

List& List::operator=(const List& rhs) {
    if (&rhs == this) {  // CHECK FOR SELF-COPYING
        return *this;    
    }
    capacity = rhs.capacity;           // Copy non-pointer members
    num_entries = rhs.num_entries;     //
    
    delete[] listptr;                  // Delete old array,     
    listptr = new string[capacity];    // and make new one

    for (int i = 0; i < capacity; ++i) {  // Copy contents from rhs to lhs
        listptr[i] = rhs.listptr[i];      //
    }                                     //
    
    return *this;  // The main value of this is to allow chained assignment
}

List::~List() {
    delete[] listptr;
}