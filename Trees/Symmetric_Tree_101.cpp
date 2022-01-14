#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Symmetric_Tree" << endl;
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

bool isSymmetrichelp(TreeNode* left, TreeNode* right)
{
    if (left == NULL || right == NULL) return (left == right);

    if (left->val != right->val) return false;

    return isSymmetrichelp(left->left, right->right) && isSymmetrichelp(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return (root == NULL) || isSymmetrichelp(root->left, root->right);
}