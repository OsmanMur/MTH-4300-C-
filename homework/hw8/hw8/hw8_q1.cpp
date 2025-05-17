// HW 8, Question 1
#include <iostream>
#include <string>

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
    int length;
public:
    LinkedList();
    void print() const;

    void push_front(const T&); 
    void pop_front();
    T get_front() const;
    
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);

    void insert_after(const T&, int);
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
    ++length;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (head != nullptr) {
        Node<T> *new_head = head->next;
        delete head;
        head = new_head;
        --length; 
    } else {
        throw std::runtime_error("Can't do that");
    }
}

template<typename T>
T LinkedList<T>::get_front() const {
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
    length = 0; 
}



/////// Part B: Implement insert_after()
template<typename T>
void LinkedList<T>::insert_after(const T& data, int n) {
    if (n > length || n < 1) {
        throw std::runtime_error("Can't do that");
    }

    Node<T>* current = head;
    for (int i = 1; i < n; ++i) {
        current = current->next;
    }

    Node<T>* new_node = new Node<T>(data, current->next);
    current->next = new_node;
    ++length;
}
/////// Part C: Implement the copy constructor.  Be careful!
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy){
    head = nullptr;
    length = copy.length; 
    if (copy.head == nullptr) {
        return; 
    }

    head = new Node<T>(copy.head->data);
    Node<T>* original = copy.head->next; 
    Node<T>* new_list_node = head;

    while (original != nullptr) {
        new_list_node->next = new Node<T>(original->data);
        new_list_node = new_list_node->next;
        original = original->next;
    }
}

/////// Part D: You don't have to do anything, but check this function out, it's neat.
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
    if(this == &rhs) {
        return *this;
    }
    LinkedList local_copy(rhs); // Cheating: using the copy constructor
    length = local_copy.length;

    // Swap local_copy.head with this->head
    Node<T>* temp = head;
    head = local_copy.head;
    local_copy.head = temp;
    
    return *this;
    // Now, local_copy goes out of scope.  Since you've swapped the original contents of `*this` with `local_copy`,
    // the destructor on `local_copy` deallocates all the original memory for `*this`.  Super clever!
}


int main() {
    LinkedList<int> my_numbers;
    my_numbers.push_front(42);  my_numbers.push_front(23);  my_numbers.push_front(16);  my_numbers.push_front(15);
    my_numbers.push_front(8);  my_numbers.push_front(4);  
    
    my_numbers.insert_after(40, 5); // 4 8 15 16 23  -> 40 <-  42
    my_numbers.insert_after(99, 7); // 4 8 15 16 23 40 42   -> 99 <- 
    cout << "If insert_after() works, you should see 4 8 15 16 23 40 42 99: ";
    my_numbers.print();

    //Uncomment after you complete part c
    LinkedList<int> empty;
    LinkedList<int> copy1 = empty, copy2 = my_numbers;

    
    cout << "Here's an empty list -- we should see nothing: ";
    copy1.print();
    cout << "This should be 4 8 15 16 23 40 42 again, if the copy assignment works: ";
    copy2.print();

    copy2.push_front(1000); copy2.push_front(1000); copy2.push_front(1000); copy2.push_front(1000);
    cout << "This should STILL be 4 8 15 16 23 40 42 -- there shouldn't be any other numbers in front: ";
    my_numbers.print();
    
    my_numbers = copy2;
    cout << "However, THIS should have 1000 in front several times: ";
    my_numbers.print();

    return 0;  
}