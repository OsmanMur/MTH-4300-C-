////////////////////////////////////////////////////////////////////////////////
// hw7_q4.cpp
////////////////////////////////////////////////////////////////////////////////
// Name:  osman
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


/////////////////////////////////////
// WRITE THE FUNCTION get() BELOW
/////////////////////////////////////

string get(Node *head, int n) {
    Node* current = head;
    int count = 1;
    while (current != nullptr) {
        if (count == n) {
            return current->data;
        }
        current = current->next;
        count++;
    }
    return "";
}

/************************************
PUT YOUR SECOND VERSION OF get() IN
THIS COMMENT

string get(Node *head, int n) {
    if (head == nullptr) {
        return "";
    }
    if (n == 1) {
        return head->data;
    }
    return get(head->next, n - 1);
}



************************************/


int main(){
    Node n5("Rich");
    Node n4("Joe", &n5);
    Node n3("Rob", &n4);
    Node n2("Ryan", &n3);
    Node n1("Okapi", &n2);
    Node *head = &n1;

	cout << get(head, 1) << endl; 
	cout << get(head, 4) << endl;
}