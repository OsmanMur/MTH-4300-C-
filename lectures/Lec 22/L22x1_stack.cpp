////////////////////////////////////////////////////////////////////////////////
// Stack
// A linked list implementation of a stack
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
class Stack {
private:
    Node<T> *top;
public:
	Stack();
	void push(const T&);
	void pop();
    bool is_empty() const;
	T peek() const;

    ~Stack();
    void operator=(const Stack&) = delete; // Lazy -- prohibiting copying, 
    Stack(const Stack&) = delete;    // but maintains Rule-of-3 compliance
};

int main() {
    Stack<int> xyz; //declare a new stack, which sets up a Node <T> *top (xyz.top that holds nothing at first (nullptr))
    xyz.push(20);
    xyz.push(30);
    xyz.pop();

    Stack<char> inputs;
    cout << "Enter characters, with '~' representing UNDO: ";
    string entry;
    std::getline(cin, entry);

    for (int i = 0; i < entry.size(); ++i) {
        if (entry[i] == '~') {
            inputs.pop();
        } else {
            inputs.push(entry[i]);
        }
    }

    while (!inputs.is_empty()){
        cout << inputs.peek();
        inputs.pop();
    }
    
    return 0;  
}



template<typename T>
Stack<T>::Stack(): top{nullptr} {
}

/* Add a new entry to the top of the stack
   @param s    Data of new entry
*/
template<typename T>
void Stack<T>::push(const T &s) {
    /////// ???
    top = new Node<T> (s, top);

}

/* Remove entry from the top of the stack
   If there stack is empty, do nothing
*/
template<typename T>
void Stack<T>::pop() {
    /////// ???
    if (top != nullptr){ // or if (!is_empty()) --> helper functions
        Node <T> *old_top = top;
        top = top -> next;
        delete old_top;
        
    }
}

/* Checks if the stack is empty
   @return     true if the stack is empty, false otherwise
*/
template<typename T>
bool Stack<T>::is_empty() const {
    return top == nullptr;
}

/* Returns the value at the top of the stack without removing it
   @return     data in top entry of the stack
*/
template<typename T>
T Stack<T>::peek() const {
    /////// ???
    if(!is_empty()){
        return top -> data;\
    } else {
        throw std::runtime_error ("Can't do that"); 
        // should throw an exception because having it return nothing 
        // as it can be misleading.
    }
}


template<typename T>
Stack<T>::~Stack() {
    while(!is_empty()) {
        pop();
    }
}