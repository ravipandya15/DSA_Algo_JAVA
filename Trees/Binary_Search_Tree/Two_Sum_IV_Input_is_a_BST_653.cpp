#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Two_Sum_IV_Input_is_a_BST_653.cpp" << endl;
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




//in JAVA filename is BSTIterator.java




class BSTIterator {
private: 
    stack<TreeNode*> stack;
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        // this flag must be set to isReverse before PushAll() function -> 
        //otherwise PushAll function will perform for reverse = true
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = stack.top();
        stack.pop();
        if (reverse) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }

private:
    void pushAll(TreeNode* node)
    {
        while (node != NULL)
        {
            stack.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }
};

bool findTarget(TreeNode* root, int k) {
    if (root == NULL) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();  // this is r.before() find of thing
    while (i < j)
    {
        if ((i + j) == k) return true;
        else if ((i + j) < k) i = l.next();
        else j = r.next();
    }
    return false;  
}