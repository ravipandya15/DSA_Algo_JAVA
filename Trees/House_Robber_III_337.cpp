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

pair<int, int> solve(TreeNode* root)
{
    if (root == NULL)
    {
        return {0,0};
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> result;

    // included
    result.first = root->val + left.second + right.second;

    // excluded
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

int rob(TreeNode* root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

