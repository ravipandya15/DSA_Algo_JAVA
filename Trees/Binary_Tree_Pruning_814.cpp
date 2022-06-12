#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
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

// 1 means we have 0
int solve(TreeNode* root)
{
    if (root == NULL) return 1;

    int left = solve(root->left);
    int right = solve(root->right);

    if (root->val == 0 && left == 1 && right == 1)
    {
        return 1;
    }

    if (left == 1)
    {
        root->left = NULL;
    }
    if (right == 1)
    {
        root->right = NULL;
    }
    
    return 0;
}
 
TreeNode* pruneTree(TreeNode* root) {
    // root will not be null
    if (root == NULL) return root;
    int data = solve(root);
    if (data == 1) return NULL;
    return root;
}