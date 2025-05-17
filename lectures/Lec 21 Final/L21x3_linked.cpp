////////////////////////////////////////////////////////////////////////////////
// Linked
// A linked list class with templates!
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

template<typename T>
struct Node {
	T data;
	Node *next;
	Node(T s, Node *n = nullptr): data{s}, next{n} {}	
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;
public:
    LinkedList();
    void print() const;

    // There are various ways to insert, delete and read data from a LinkedList. So as to not make ourselves crazy, 
    // let's just implement insertion, deletion, and reading from the FRONT.
    void push_front(const T&); // Adds a new Node to the front
    void pop_front();          // Removes the front Node
    T get_front();             // Returns the front Node's data
    
    // Rule of 3: because we're lazy, we'll simply prohibit any type of copying, using `= delete`.  But we still need to deallocate!
    ~LinkedList();
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

};

template<typename T>
LinkedList<T>::LinkedList(): head{nullptr} {
}

template<typename T>
void LinkedList<T>::print() const {
    Node<T> *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template<typename T>
void LinkedList<T>::push_front(const T& data) {
    head = new Node<T>(data, head);  
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (head != nullptr) {
        Node<T> *new_head = head->next;
        delete head;
        head = new_head;
    } else {
        throw std::runtime_error("Can't do that");
    }
}

template<typename T>
T LinkedList<T>::get_front() {
    if (head != nullptr) {
        return head->data;
    } else {
        throw std::runtime_error("Can't do that");
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        pop_front();
    }
}



int main() {
    LinkedList<int> my_numbers;
    my_numbers.push_front(42);  my_numbers.push_front(23);  my_numbers.push_front(16);  my_numbers.push_front(15);
    my_numbers.push_front(8);  my_numbers.push_front(4);  my_numbers.push_front(1234567);
    
    my_numbers.pop_front();
    
    cout << "Hurley's numbers are: ";
    my_numbers.print();

    return 0;  
}