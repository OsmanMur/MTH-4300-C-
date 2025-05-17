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
    
    cout << (*head).data; // first name
    cout << head->data;

    cout << (*((*head).next)).data; // second name
    cout << head->next->data;

    cout << (*((*((*head).next)).next)).data; // third name
    cout << (head->next->next)->data;



    // `current` denotes a pointer to the element we are currently "processing" (i.e. printing)
    cout << "Linked list contents: " << endl;
    Node *current = head;       // `current` starts out as `head`, then gets updated.
    
    while (current != nullptr){ //  keeps going until current is nullptr!
        cout << current->data << endl;
        current = current->next;
    }

    current = head;



    // Now, let's demonstrate where Linked Lists shine: insertion and removing!
    // Remove "Carol" from the list

    n2.next = &n4;


    cout << "\nAfter removing Carol, new Linked list contents: " << endl;
    
    current = head;

    while (current != nullptr){ //  keeps going until current is nullptr!
        cout << current->data << endl;
        current = current->next;
    }

    current = head;

    
    return 0;  
}