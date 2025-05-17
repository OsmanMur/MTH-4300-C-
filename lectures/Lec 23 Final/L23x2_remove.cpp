////////////////////////////////////////////////////////////////////////////////
// Remove
// Implementation of a remove function for a binary search tree.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

template<typename T>
struct TreeNode {
	T data;
	TreeNode *left, *right;
	TreeNode(T d, TreeNode *l = nullptr, TreeNode *r = nullptr): data{d}, left{l}, right{r} {}	
};

/* Remove the node in a tree which is pointed to by `root`, leaving behind a valid binary search tree.
   @param root     A pointer to the node which we wish to remove.  
                   If the node to be removed is not the root of the tree, `root` should be the `left` or `right`
                   attribute of the parent.
*/
template<typename T>
void remove_root_bst(TreeNode<T>* &root) {
    if (root == nullptr) {
        // Nothing to remove if `root` is a nullptr
        return;
    } else if (root->left == nullptr) {
        // If the node to remove has no left child, simply make root point to the right child
        TreeNode<T>* temp = root;
        root = root->right;
        delete temp;
    } else if (root->right == nullptr) {
        // If the node to remove has no right child, simply make root point to the left child
        TreeNode<T>* temp = root;
        root = root->left;
        delete temp;
    } else if (root->right->left == nullptr) {
        // The first "subcase": the node to remove has two children,
        // BUT the right child is the successor of the node to remove.
        TreeNode<T>* successor = root->right;
        successor->left = root->left;
        delete root;
        root = successor;
    } else {
        // The second "subcase": the node to remove has two children,
        // and the right child is NOT the successor.

        // First, locate the successor and the successor's parent
        TreeNode<T> *successor_parent = root; 
        TreeNode<T> *successor = root->right;
        while (successor->left != nullptr) {
            successor_parent = successor;
            successor = successor->left;
        }

        // The successor will be the left child of the parent, and the successor will have no left child.  (Think about why!!!!!)
        // Make successor's right child into the parent's left child
        successor_parent->left = successor->right;

        // Prepare successor to be the new root node
        successor->left = root->left;
        successor->right = root->right;
        
        // Delete the old root, and update root so that it now points to the newly edited successor node. 
        delete root;
        root = successor;
    }
}


/* Adds a TreeNode with data given by `entry` to the tree whose root is pointed to by `t`.
   @param t        Pointer to the root node of a tree
   @param entry    Data for the Node added to the tree
*/
template <typename T>
void insert_bst(TreeNode<T>* &t, const T &entry){
    // It's essential that the nullptr case goes first, to that there is no checking of t->data.
    if(t == nullptr) {     
        t = new TreeNode(entry);
    } else if (entry <= t->data) {
        insert_bst(t->left, entry);
    } else {
        insert_bst(t->right, entry);
    }
}


/* Prints data in the tree pointed to by `t` in increasing order
   @param t        Pointer to the root node of a tree
*/
template <typename T>
void print(TreeNode<T>* &t) {
    if (t != nullptr) {
        print(t->left);
        cout << t->data << " ";
        print(t->right);
    }
}

/* Returns a pointer to a node in tree pointed to by `t` which has data given by `entry`, if one exists.
   Otherwise returns nullptr.
   @param t        Pointer to the root node of a tree
   @param entry    Data being searched for
   @return         nullptr if no node has data equal to `entry`, or a pointer to the node whose data is equal to `entry`.
*/
template <typename T>
TreeNode<T>*& search_bst(TreeNode<T>* &t, const T &entry) {
   // It's essential that the nullptr case goes first, so that there is no checking of t->data.
    if (t == nullptr || t->data == entry) {
        return t;
    } else if (t->data > entry) {
        return search_bst(t->left, entry);
    } else {
        return search_bst(t->right, entry);
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
    
    
    print<string>(t);
    
    cout << endl;

    // Here's how we use the remove function.  These lines are what make it 
    // essential that search_bst() returns by REFERENCE.
    // Indeed, the variable `remove` needs to be a reference variable for this 
    // to work!  You want to modify within the tree that exists, 
    // rather than modifying some random variable holding the address of a node.
    TreeNode<string>* &remove = search_bst<string>(t, "Blue");
    remove_root_bst<string>(remove);
    
    print<string>(t);
    return 0;  
}