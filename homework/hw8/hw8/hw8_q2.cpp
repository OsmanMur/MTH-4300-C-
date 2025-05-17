// HW 8, Question 2
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
class Queue {
private:
    Node<T> *front;
    Node<T> *back;
public:
    Queue();
    bool is_empty();
    void push_back(const T&);
    T pop_front();
    void print_queue();
    ~Queue();
    void operator=(const Queue&) = delete; 
    Queue(const Queue&) = delete;    
};

// Now, implement all the functions!
template<typename T>
Queue<T>::Queue(): front{nullptr}, back{nullptr} {}


template<typename T>
bool Queue<T>::is_empty() {
    return front == nullptr;
}

template<typename T>
void Queue<T>::push_back(const T& s) {
    Node<T>* new_node = new Node<T>(s);
    if (is_empty()) {
        front = back = new_node; 
    } else {
        back->next = new_node; 
        back = new_node;       
    }
}

template<typename T>
T Queue<T>::pop_front() {
    if (is_empty()) {
        throw std::runtime_error("Can't do that");
    }
    Node<T>* old_front = front;
    T data = old_front->data;
    front = front->next;
    if (front == nullptr) {
        back = nullptr; 
    }
    delete old_front; 
    return data;
}

template<typename T>
void Queue<T>::print_queue() {
    Node<T>* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


template<typename T>
Queue<T>::~Queue() {
    while (!is_empty()) {
        pop_front();
    }
}


int main() {
    Queue<string> x;
    x.push_back("A");
    x.push_back("B");
    x.push_back("C");
    
    cout << "After A, B, and C are pushed, here's what's in the queue: ";
    x.print_queue();

    cout << "Now, a call to .pop_front() yields: " << x.pop_front() << endl;
    cout << "And now the queue contains: ";
    x.print_queue();
 
    x.push_back("D");
    x.push_back("E");
    x.pop_front();
    
    cout << "Finally, at the end, the contents of the queue are: ";
    x.print_queue();
    return 0;
}

