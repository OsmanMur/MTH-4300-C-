////////////////////////////////////////////////////////////////////////////////
// Trees
// The basics of binary trees.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>

using std::cout; using std::cin; using std::endl; using std::string;


template<typename T>
struct TreeNode {
	T data;
	TreeNode *left, *right;
	TreeNode(T d, TreeNode *l = nullptr, TreeNode *r = nullptr): data{d}, left{l}, right{r} {}	
};

/* Returns the height of the tree pointed to by `t`, where the height is the maximal number of Nodes passed
   through in a path from the root to a leaf
   @param t     A pointer to the root node of a Tree
   @return      The height of the tree
*/
template<typename T>
int height(TreeNode<T> *t) {
    if (t == nullptr){
        return 0;
    }
    return 1 + std::max(height(t->left), height(t->right));
}

/* Returns the size of the tree pointed to by `t`, where the size is the number of Nodes in the tree
   @param t     A pointer to the root node of a Tree
   @return      The size of the tree
*/
template<typename T>
int size(TreeNode<T> *t) {
    if (t == nullptr){
        return 0;
    }
    return 1 + size(t->left) + size(t->right);
}

int main() {
    TreeNode<string> *my_tree;
    my_tree = new TreeNode<string>("A");
    my_tree->left = new TreeNode<string>("B");
    my_tree->right = new TreeNode<string>("C");
    my_tree->left->left = new TreeNode<string>("D");
    my_tree->left->right = new TreeNode<string>("E");
    my_tree->right->left = new TreeNode<string>("F");
    my_tree->left->right->right = new TreeNode<string>("G");


    // SUGGESTION: in VS Code, click to the left of the line number on the line below,
    // and choose "Start Debugging".  You should be able to inspect the contents of my_tree,
    // including seeing which pointers are NULL (0x0).
    cout << height(my_tree) << " " << size(my_tree);

    return 0;  
}