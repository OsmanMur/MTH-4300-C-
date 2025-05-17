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
    void reserve();
public:
    List(int);
    List();
    void append(const string&);
    string& operator[](int);
    void print() const; // For ease of testing
};
#endif