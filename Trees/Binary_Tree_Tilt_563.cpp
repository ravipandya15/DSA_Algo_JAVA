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

int solve(TreeNode* root, int& result)
{
    // base case
    if (root == NULL) return 0;
    int leftSum = solve(root->left, result);
    int rightSum = solve(root->right, result);
    result += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
}

int findTilt(TreeNode* root) {
    int result = 0;
    solve(root, result);
    return result;
}

