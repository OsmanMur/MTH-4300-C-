#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    Stack(): top{nullptr} {}
    void push(const T&);
    void pop();
    bool is_empty() const;
    T peek() const;
    ~Stack();
    
    void operator=(const Stack&) = delete; // Lazy -- prohibiting copying, 
    Stack(const Stack&) = delete;          // but maintains Rule-of-3 compliance
};

template<typename T>
void Stack<T>::push(const T &s) { top = new Node<T>(s, top); }

template<typename T>
void Stack<T>::pop() {
    if (!is_empty()) {
        Node<T> *temp = top->next;
        delete top;
        top = temp;
    }
}

template<typename T>
bool Stack<T>::is_empty() const { return top == nullptr; }

template<typename T>
T Stack<T>::peek() const {
    if (is_empty()) {
        throw std::runtime_error("Can't do that");
    }
    return top->data;
}
template<typename T>
Stack<T>::~Stack() {
    while(!is_empty()) {
        pop();
    }
}


int main() {
    vector<string> sandwich_line = {"PAlice", "PBob", "JCarol", "JDennis", "JEvan", "PFrank", "JGeorge"};
}