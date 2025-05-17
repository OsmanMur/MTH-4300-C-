////////////////////////////////////////////////////////////////////////////////
// Remove
// Given the data for a Node and a head pointer, remove an element
// from the list. 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
	string data;
	Node *next;
    // Let's provide a default value in the constructor.
	Node(string s, Node* n = nullptr): data{s}, next{n} {}	
};

void print_list(Node *current) {
    while(current != nullptr) {
	    cout << current->data << " ";
	    current = current->next;
    }
    cout << endl;
}

int main() {
    Node n4("Evan");    // Taking advantage of the default constructor.
    Node n3("Carol", &n4);     Node n2("Bob", &n3);     Node n1("Alice", &n2);  
    Node *head = &n1;
    print_list(head);

    Node *current = head;   // The Node we're currently looking at
    Node *prev = nullptr;   // The one before that -- initially, nullptr

    // Let's try and write code that finds and removes "Carol" 
    while(current != nullptr) {
        if (current->data == "Carol") {
            if (prev == nullptr) {      // This case ensures that removal still works
                head = current->next;   // when value is in first node.
            } else {
                prev->next = current->next;
            }
            break;
        }
        prev = current;
        current = current->next;
    }
    

    cout << "Check: after removal, Linked list contents are " << endl;
    print_list (head);
    return 0;  
}