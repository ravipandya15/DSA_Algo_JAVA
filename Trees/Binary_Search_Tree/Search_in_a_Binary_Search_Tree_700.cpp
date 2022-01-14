#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Search_in_a_Binary_Search_Tree_700.cpp" << endl;
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

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root->val != val)
    {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}