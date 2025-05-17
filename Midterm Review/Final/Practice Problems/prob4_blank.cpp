#include <iostream>
#include <string>

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
    TreeNode<string>* the_tree = new TreeNode<string>(""); // the root of the tree will be the empty string.
    insert<string>(the_tree, "middle");
    insert<string>(the_tree, "ant");
    insert<string>(the_tree, "dog");
    insert<string>(the_tree, "greetings");
    insert<string>(the_tree, "cat");
    insert<string>(the_tree, "dog");
    insert<string>(the_tree, "rhinoceros");
    insert<string>(the_tree, "dog");

    cout << "dog appears " << count<string>(the_tree, "dog") << " times (should be 3)" << endl;
    cout << "cat appears " << count<string>(the_tree, "cat") << " times (should be 1)" << endl;
    cout << "AHeta5h535q!# appears " << count<string>(the_tree, "AHeta5h535q!#") << " times (should be 0)" << endl;
}
