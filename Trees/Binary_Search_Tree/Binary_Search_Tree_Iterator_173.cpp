#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Binary_Search_Tree_Iterator_173.cpp" << endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private: stack<TreeNode*> stack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }

private:
    void pushAll(TreeNode* node)
    {
        for (; node != NULL; stack.push(node), node = node->left);
        // in while loop
        //while (node != null)
        //{
        //    stack.Push(node);
        //    node = node.left;
        //}
    }
};

