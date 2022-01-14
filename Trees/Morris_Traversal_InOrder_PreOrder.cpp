#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "Morris_Traversal_InOrder_PreOrder.cpp" << endl;
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

vector<int> inorderTraversal(TreeNode* root) {
    // Morris_Inorder
    // TC -> O(N), SC -> O(1)
    vector<int> morris_Inorder;
    TreeNode* cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            morris_Inorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            // go to right most down most node of left subtree
            TreeNode* prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                // make pointer pointer
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                // means prev.right == cur
                prev->right = NULL;
                morris_Inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return morris_Inorder;       
}

vector<int> preorderTraversal(TreeNode* root) {
    // Morris_Preorder
    // TC -> O(N), SC -> O(1)
    vector<int> morris_Preorder;
    TreeNode* cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            morris_Preorder.push_back(cur->val);
            cur = cur->right;
        }
        else
        {
            // go to right most down most node of left subtree
            TreeNode* prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                // make pointer pointer
                prev->right = cur;
                morris_Preorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                // means prev.right == cur
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return morris_Preorder;  
}