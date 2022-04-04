#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL) return false;
    if (root2 == NULL) return false;
    
    if (root1->val != root2->val) return false;
    
    if ( (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) 
        || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) )
    {
        return true;
    }
    else
    {
        return false;
    }
}