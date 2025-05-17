////////////////////////////////////////////////////////////////////////////////
// Add
// Add in a new element
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
	string data;
	Node *next;
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
    Node n4("Evan");    Node n3("Carol", &n4);    Node n2("Bob", &n3);    Node n1("Alice", &n2);  
    
    Node *head = &n1;
    print_list(head);

    // New entry:
    string entry = "Dennis";

    Node *current = head;   // The Node we're currently looking at
    Node *prev = nullptr;   // The one before that -- initially, nullptr

    // Let's try and write code that adds "Dennis" in alphabetical order.
    // Bonus points: can we make this code properly handle insertions at the beginning or end of the list?



    

    cout << "Check: after insertion, Linked list contents are " << endl;
    print_list (head);
 
    return 0;  
}