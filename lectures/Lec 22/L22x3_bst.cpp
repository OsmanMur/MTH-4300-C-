////////////////////////////////////////////////////////////////////////////////
// BST
// Implementations of insert, print, and search for a Binary Search Tree
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using std::cout; using std::cin; using std::endl; using std::string;

template<typename T>
struct TreeNode {
	T data;
	TreeNode *left, *right;
	TreeNode(T d, TreeNode *l = nullptr, TreeNode *r = nullptr): data{d}, left{l}, right{r} {}	
};




/* Prints data in the tree pointed to by `t` in increasing order
   @param t        Pointer to the root node of a tree
*/
template <typename T>
void print(TreeNode<T>* t) {



}

/* Returns a pointer to a node in tree pointed to by `t` which has data given by `entry`, if one exists.
   Otherwise returns nullptr.
   @param t        Pointer to the root node of a tree
   @param entry    Data being searched for
   @return         nullptr if no node has data equal to `entry`, or a pointer to the node whose data is equal to `entry`.
*/

// While it's not entirely obvious why, it will be important when we use this function later
// as part of removing items from a BST that the function return by REFERENCE.  Because of that
// the input pointer must also be a reference.
template <typename T>
TreeNode<T>*& search_bst(TreeNode<T>* &t, const T &entry) {





}



/* Adds a TreeNode with data given by `entry` to the tree whose root is pointed to by `t`.
   @param t        Pointer to the root node of a tree
   @param entry    Data for the Node added to the tree
*/
template <typename T>
void insert_bst(TreeNode<T>* &t, const T &entry){
    // It's essential that the nullptr case goes first, so that there is no checking of t->data.



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
    
    print<string>(t);
    cout << endl;
    cout << "Search results for Igloo:" << search_bst<string>(t, "Igloo") << endl;
    cout << "Search results for Zebra:" << search_bst<string>(t, "Zebra") << endl;
    
    return 0;  
}