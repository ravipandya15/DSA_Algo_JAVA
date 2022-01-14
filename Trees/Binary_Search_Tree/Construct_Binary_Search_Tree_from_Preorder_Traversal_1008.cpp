#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Construct_Binary_Search_Tree_from_Preorder_Traversal_1008.cpp" << endl;
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

// bound is upper bound, value should not be greater than or equal to bound
TreeNode* buildBST(vector<int>& preOrder, int bound, int& i)
{
    if (i == preOrder.size() || preOrder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preOrder[i++]);
    root->left = buildBST(preOrder, root->val, i);
    root->right = buildBST(preOrder, bound, i);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return buildBST(preorder, INT_MAX, i);
}