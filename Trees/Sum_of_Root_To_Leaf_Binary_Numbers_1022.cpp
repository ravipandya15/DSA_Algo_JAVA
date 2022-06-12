#include<iostream>
#include<vector>
#include<queue>
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

int solve(TreeNode* root, int &val)
{
    if (root == NULL)
    {
        return 0;
    }
    val = val * 2 + root->val;
    if (root->left == root->right)
    {
        return val;
    }
    int left = solve(root->left, val);
    int right = solve(root->right, val);
    return left + right;
}

// here int val = 0 parameter is added by me -> 
int sumRootToLeaf(TreeNode* root, int val = 0) {
    // base case
    if (root == NULL) 
    {
        return 0;
    }

    val = val * 2 + root->val;
    if (root->left == root->right)
    {
        return val;
    }
    int left = sumRootToLeaf(root->left, val);
    int right = sumRootToLeaf(root->right, val);
    return left + right;
}