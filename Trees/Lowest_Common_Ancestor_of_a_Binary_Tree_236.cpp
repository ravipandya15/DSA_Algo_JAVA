#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Lowest_Common_Ancestor_of_a_Binary_Tree_236" << endl;
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // this will also work
    //if (left != null && right != null) return root;
    //else if (left != null) return left;
    //else return right;

    if (left == NULL) return right;
    else if (right == NULL) return left;
    else
    { // both left and right are not null, we found our ans
        return root;
    }
}