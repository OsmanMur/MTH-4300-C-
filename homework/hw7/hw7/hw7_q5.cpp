////////////////////////////////////////////////////////////////////////////////
// hw7_q5.cpp
////////////////////////////////////////////////////////////////////////////////
// Name: osman
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

struct Node {
    string data;
    Node *next;
    Node(string s, Node* n = nullptr): data{s}, next{n} {}	
};

void print_list(Node *head){
	Node *current = head;
	while(current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}


//////////////////////////////////////////
// WRITE THE FUNCTION remove_Rs() BELOW
//////////////////////////////////////////


void remove_Rs(Node* &head) {
    if (head == nullptr){
        return;
    }

    if (head->data[0] == 'R') {
        head = head->next; 
        remove_Rs(head);
        
    } else {
        remove_Rs(head->next);
    }
}



int main(){
    Node n5("Rich");
    Node n4("Joe", &n5);
    Node n3("Rob", &n4);
    Node n2("Ryan", &n3);
    Node n1("Okapi", &n2);
    Node *head = &n1;
	
	remove_Rs(head);
	print_list(head);
}