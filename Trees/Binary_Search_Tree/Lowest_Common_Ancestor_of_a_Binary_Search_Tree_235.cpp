#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Lowest_Common_Ancestor_of_a_Binary_Search_Tree_235.cpp" << endl;
    return 0;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    return root;
}

TreeNode* lowestCommonAncestor_Iterative(TreeNode* root, TreeNode* p, TreeNode* q) {
    //Iterative
    while (root != NULL)
    {
        if (p->val > root->val && q->val > root->val)
        {
            root = root->right;
        }
        else if (p->val < root->val && q->val < root->val)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    return root;
}