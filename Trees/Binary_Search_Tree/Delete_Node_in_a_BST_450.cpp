#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Delete_Node_in_a_BST_450.cpp" << endl;
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

TreeNode* findLastNodeInLeftSubTree(TreeNode* root)
{
    if (root->right == NULL) return root;
    return findLastNodeInLeftSubTree(root->right);
}

TreeNode* helper(TreeNode* root)
{
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;

    // means both left and right part exist;
    // task is to find last node is left sub tree and right of that should be root->right;

    TreeNode* rightChild = root->right;
    TreeNode* lastNodeInLeftSubTree = findLastNodeInLeftSubTree(root->left);
    lastNodeInLeftSubTree->right = rightChild;
    return root->left;
}

// TC -> O(logN) -> Log N base 2
// SC -> O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->val == key) return helper(root);
    TreeNode* dummy = root;

    while (root != NULL)
    {
        if (root->val > key)
        {// go left side
            if (root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {// go ti right side
            if (root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}