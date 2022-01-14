#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Validate_Binary_Search_Tree_98.cpp" << endl;
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

bool isValidBST(TreeNode* root, long minVal, long maxVal)
{
    if (root == NULL) return true;

    if (root->val >= maxVal || root->val <= minVal) return false;

    return isValidBST(root->left, minVal, root->val)
        && isValidBST(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}