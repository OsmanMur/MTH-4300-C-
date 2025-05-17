////////////////////////////////////////////////////////////////////////////////
// Linked
// A Linked List 
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
	string data;
	Node *next;
	Node(string s, Node* n): data{s}, next{n} {}	
};

int main() {
    Node n1("Alice", nullptr);
    Node n2("Bob", nullptr);
    Node n3("Carol", nullptr);
    Node n4("Evan", nullptr);

    // Let's manually add in the linking:
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    // We will let `head` denote the first element of the list.
    Node *head = &n1;

    // `current` denotes a pointer to the element we are currently "processing" (i.e. printing)
    cout << "Linked list contents: " << endl;
    Node *current = head;       // `current` starts out as `head`, then gets updated.
    while(current != nullptr) {
	    cout << current->data << " ";
	    current = current->next;
    }    

    // Now, let's demonstrate where Linked Lists shine: insertion and removing!
    // Remove "Carol" from the list
    n2.next = &n4;      // That's it!  Now, check:

    cout << "\nAfter removal, new Linked list contents: " << endl;
    current = head;
    while(current != nullptr) {
	    cout << current->data << " ";
	    current = current->next;
    }

    return 0;  
}