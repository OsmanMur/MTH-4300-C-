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


int main() {
    TreeNode<string> *my_tree;
    my_tree = new TreeNode<string>("A");
    my_tree->left = new TreeNode<string>("B");
    my_tree->right = new TreeNode<string>("C");
    my_tree->left->left = new TreeNode<string>("D");
    my_tree->right->left = new TreeNode<string>("E");
    my_tree->right->left->right = new TreeNode<string>("F");

    reverse<string>(my_tree);

    cout << "<--- Set a breakpoint in the debugger in VS to check your work!";

}