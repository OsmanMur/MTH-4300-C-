#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
public:
    T data;
    int count;
    TreeNode *left, *right;
    TreeNode(T s, TreeNode* l = nullptr, TreeNode *r = nullptr): data{s}, left{l}, right{r}, count{1} {}
};

template <typename T>
void insert_bst(TreeNode<T>* &t, const T &entry){
    if(t == nullptr) {     
        t = new TreeNode(entry);
    } else if (entry <= t->data) {
        insert_bst(t->left, entry);
    } else {
        insert_bst(t->right, entry);
    }
}



int main() {
    TreeNode<string>* t = nullptr;
    insert_bst<string>(t, "Hello");
    insert_bst<string>(t, "Goodbye");
    insert_bst<string>(t, "Blue");
    insert_bst<string>(t, "Apple");
    insert_bst<string>(t, "Jack");
    insert_bst<string>(t, "Kangaroo");
    insert_bst<string>(t, "Igloo");
    insert_bst<string>(t, "Cherry");
    
    cout << "Should print out 0323-1:\n";
    cout << level_bst<string>(t, "Hello") << level_bst<string>(t, "Apple") << level_bst<string>(t, "Igloo") << level_bst<string>(t, "Cherry") << level_bst<string>(t, "Zebra");
}