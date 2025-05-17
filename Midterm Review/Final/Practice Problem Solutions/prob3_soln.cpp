#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
    string data;
    Node *next;
    Node(string s, Node* n): data{s}, next{n} {}	
};

// Prints linked list in order
void print_list(Node *listptr) {
	Node *current = listptr;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

//
// REVERSE
//
Node* reverse(Node* listptr) {
    Node* curr = listptr;
    Node* prev = nullptr;
    while (curr != nullptr) {
        Node* follow = curr->next;
        curr->next = prev;
        prev = curr;
        curr = follow;
    }
    return prev;
}

/// RECURVSIVE VERSION 
/*Node* reverse(Node* listptr) {
    if (listptr == nullptr) {
        return nullptr;
    } else if (listptr->next == nullptr) {
        return listptr;
    } else {
        Node* follow = listptr->next;
        Node* ret_value = reverse(follow);
        follow->next = listptr;
        listptr->next = nullptr;
        return ret_value;
    }
}*/



int main() {
    Node n1("Alice", nullptr);   Node n2("Bob", nullptr);   Node n3("Carol", nullptr);   Node n4("Evan", nullptr);
    Node *head = &n1;
    n1.next = &n2;    n2.next = &n3;    n3.next = &n4;

    head = reverse(head);
    print_list(head);
}