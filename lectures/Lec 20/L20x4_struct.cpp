////////////////////////////////////////////////////////////////////////////////
// Struct
// An example of the use of templates
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

// For Nodes of a linked list of data with type `DataType`
template<typename DataType>    
struct Node {
    DataType data;
    Node* next;
    Node(DataType d, Node* n = nullptr): data{d}, next{n} {}
};

int main() {
    Node<int> n3(12);
    Node<int> n2(17, &n3);
    Node<int> n1(23, &n2);
    Node<int>* head = &n1;
    return 0;
}



