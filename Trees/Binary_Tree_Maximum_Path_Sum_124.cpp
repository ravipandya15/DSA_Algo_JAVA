#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "124. Binary Tree Maximum Path Sum" << endl;
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

class Solution
{
    private:
    int maxPathDown(TreeNode* node, int& maxi)
    {
        if (node == NULL) return 0;

        int leftSum = max(0, maxPathDown(node->left, maxi));
        int rightSum = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, node->val + leftSum + rightSum);

        return node->val + max(leftSum, rightSum);
    }
    public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};
