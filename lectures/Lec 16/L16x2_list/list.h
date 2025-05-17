////////////////////////////////////////////////////////////////////////////////
// list.h
// List class declaration
////////////////////////////////////////////////////////////////////////////////

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

class List {
private:
    string *listptr;
    int capacity;
    int num_entries;
    void reserve(); // private function that seeks out new memory when more space is needed. Why private? Because it's only used by the List class.
public:
    string occ[6] ={"--", "--", "--", "--", "--", "--"};//what does this do? --> This is a string array of size 6, initialized with "--". 
    List(int);//
    List();//
    void append(const string&); // what should happen ideally? -->  Add a new string to the current list.
    string& operator[](int);
    void print() const; // For ease of testing
};
#endif