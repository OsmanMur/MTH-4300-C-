#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
    string data;
    Node *next;
    Node(string s, Node* n): data{s}, next{n} {}	
};

int main(){
    Node e("Elephant", nullptr), c("Cat", &e), b("Bear", &c), a("Alligator",&b);
    Node *head = &a;
    
    // ADD CODE HERE
    Node d("Duck", &e);
    c.next = &d;

    Node *current = head;
    while(current != nullptr) {
        current->data = current->data + "s";
        current = current->next;
    }

    // CHECK by printing
    current = head;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}