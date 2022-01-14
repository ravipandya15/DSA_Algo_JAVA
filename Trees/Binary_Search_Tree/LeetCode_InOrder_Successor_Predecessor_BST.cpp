#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "LeetCode_InOrder_Successor_Predecessor_BST.cpp" << endl;
    return 0;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inOrder_Successor(TreeNode* root, TreeNode* p)
{
    TreeNode* successor = NULL;
    while(root != NULL)
    {
        if (root->val > p->val)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

TreeNode* inOrder_Predecessor(TreeNode* root, TreeNode* p)
{
    TreeNode* successor = NULL;
    while (root != NULL)
    {
        if (root->val >= p->val) root = root->left;
        else
        {
            successor = root;
            root = root->right;
        }
    }
    return successor;
}