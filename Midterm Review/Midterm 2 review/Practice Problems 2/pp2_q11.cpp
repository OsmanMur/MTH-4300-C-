// Problem 11
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
    ~List();
    List& operator=(const List&);
    List(const List&);

    /////// NEW METHODS
    void erase(int);
    void insert(int, string);
    List& operator+=(const List& rhs);
};


/////// NEW METHODS

/////// .erase()
void List::erase(int n) {
    for (int idx = n; idx < num_entries - 1; ++idx){
        listptr[idx] = listptr[idx + 1];
    }
    --num_entries;
}

/////// .insert()
void List::insert(int n, string s) {
    if (num_entries == capacity) {
        reserve();
    }
    for (int idx = num_entries; idx >= n + 1; --idx) {
        listptr[idx] = listptr[idx - 1];
    }
    listptr[n] = s;
    ++num_entries;
}

/////// operator+= 
List& List::operator+=(const List& rhs) {
    if (num_entries + rhs.num_entries > capacity) {
        // Reserve additional space
        string *temp = new string[num_entries + rhs.num_entries];
        for(int idx = 0; idx < num_entries; ++idx) {
            temp[idx] = listptr[idx];
        }
        listptr = temp;
    }
    for(int idx = 0; idx < rhs.num_entries; ++idx) {
        listptr[num_entries + idx] = rhs.listptr[idx];
    }
    num_entries += rhs.num_entries;
    return *this;
}

///////// Alternate simpler solution
/*
List& List::operator+=(const List& rhs){
    for(int idx = 0; idx < rhs.num_entries; ++idx){
        append(rhs.listptr[idx]);
    }
    return *this;
}*/

int main() {
    List test, test2;
    test.append("A");
    test.append("B");
    test.append("C");
    test2.append("D");
    test2 += test;
    test2.erase(2);
    test2.insert(1, "XYZ");
    test2.print();
}












//////////// OLD METHODS
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
    listptr = nullptr; 
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

string& List::operator[](int n) {
    return listptr[n];
}

void List::print() const {
    for(int idx = 0; idx < num_entries; ++idx) {
        cout << listptr[idx] << " ";
    }
    cout << endl;
}

List::~List() {
    delete[] listptr;
}

List::List(const List& rhs): capacity{rhs.capacity}, num_entries{rhs.num_entries} {
    listptr = new string[capacity];
    for (int idx = 0; idx < num_entries; ++idx){
        listptr[idx] = rhs.listptr[idx];
    }
}


List& List::operator=(const List& rhs) {
    if (&rhs == this) { // Protecting against
        return *this;   // the self-assignment trap
    }
    capacity = rhs.capacity;
    num_entries = rhs.num_entries;

    delete[] listptr;
    listptr = new string[capacity];
    for (int idx = 0; idx < num_entries; ++idx){
        listptr[idx] = rhs.listptr[idx];
    }
    return *this;
}




