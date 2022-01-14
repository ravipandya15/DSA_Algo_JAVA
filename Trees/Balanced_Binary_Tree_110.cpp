#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Level Order" << endl;
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

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}

int dfsHeight(TreeNode* root)
{
    if (root == NULL) return 0;

    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + max(leftHeight, rightHeight);
}