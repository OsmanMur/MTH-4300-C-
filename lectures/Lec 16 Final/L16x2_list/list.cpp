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

void List::append(const string &entry){
    if (num_entries >= capacity) {
        reserve();
    }
    listptr[num_entries] = entry;
    ++num_entries;
}

// We did not discuss this one yet.
string& List::operator[](int n) {
    return listptr[n];
}

void List::print() const {
    for(int idx = 0; idx < num_entries; ++idx) {
        cout << listptr[idx] << " ";
    }
    cout << endl;
}
