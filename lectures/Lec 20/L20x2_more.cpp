////////////////////////////////////////////////////////////////////////////////
// More
// More linked list functions -- including recursion
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
	string data;
	Node *next;
    Node(string s, Node* n = nullptr): data{s}, next{n} {}	
};

/* Prints the contents of the linked list whose first element is `*current`
   @param current     Pointer to the head of the list
*/
void print_list(Node *current) {
    if (current != nullptr) {
	    cout << current->data << " ";
	    print_list(current->next);
    } else {
        cout << endl;
    }
}

/* Returns the number of Nodes in the linked list pointed to by `h`
   @param h     Pointer to the head of the list
   @return      Number of nodes in this list
*/
int size(Node *h){
    if (h == nullptr) {
        return 0;
    }
    return 1 + size(h->next);

}


/* Adds a new entry to the end of a linked list pointed to by `h`
   @param h         Pointer to the head of the list
   @param entry     Content of node added to the end of list
*/
void append(Node* &h, string entry) {
    if (h == nullptr) {
        h = new Node(entry, nullptr);
    } else {
        append(h->next, entry);
    }
}

/* Reverses a linked list pointed to by `h`
   @param h         Pointer to the head of the list
*/
void reverse(Node* &h) {
    Node *curr = h, *prev = nullptr, *follow;
    while(curr != nullptr){
        follow = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = follow;
    }
    h = prev;

}




int main() {
    Node n4("Evan");    Node n3("Carol", &n4);  Node n2("Bob", &n3);    Node n1("Alice", &n2);  
    Node *head = &n1;
    
    //head = nullptr; //edge case test

    cout << "Original list: ";
    print_list(head);

    cout << "Size: ";
    cout << size(head) << endl;

    append(head, "Frank");
    append(head, "George");
    cout << "After two appends: ";
    print_list(head);


    reverse(head);
    cout << "After reverse: ";
    print_list(head);
    cout << "New Size: ";
    cout << size(head) << endl;
    return 0;  
}