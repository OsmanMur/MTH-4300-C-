#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Vector-based stack

template <typename T>
class Node {
public:
    T data;
    Node *next;
    Node(T s, Node* n): data{s}, next{n} {}	
};

template <typename T>
class Stack {
private:
    vector<T> stacklist; 
public:
    Stack() {}
    void push(const T&);
    bool is_empty();
    void pop();
    T peek();
    // Destructor no longer necessary       
};

template <typename T>
void Stack<T>::push(const T &s) {
    stacklist.push_back(s);
}

template <typename T>
bool Stack<T>::is_empty() {
    return stacklist.size() == 0;
}

template <typename T>
void Stack<T>::pop() {
    if (is_empty()) {
        throw std::invalid_argument("Popping from empty stack");
    }
    stacklist.erase(stacklist.end() - 1);
}

template <typename T>
T Stack<T>::peek() {
    if (is_empty()) {
        throw std::invalid_argument("Peeking empty stack");
    }
    return *(stacklist.end() - 1);
}

int main() {
    Stack<string> x;
    x.push("A");
    x.push("B");
    x.push("C");
    cout << x.peek();
    x.pop();
    x.pop();
    x.push("R");
    x.push("B");
    x.push("O");
    while (!x.is_empty()) {
        cout << x.peek();
        x.pop();
    }
}