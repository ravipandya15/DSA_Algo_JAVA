#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Insert_into_a_Binary_Search_Tree_701.cpp" << endl;
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    TreeNode* cur = root;

    while (true)
    {
        // if (cur.val < val) will also work
        if (cur->val <= val)
        {
            if (cur->right != NULL) 
                cur = cur->right;
            else
            {
                cur->right = new TreeNode(val);
                break; // IMP -> otherwise infinite loop
            }
        }
        else
        {
            if (cur->left != NULL)
                cur = cur->left;
            else
            {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}