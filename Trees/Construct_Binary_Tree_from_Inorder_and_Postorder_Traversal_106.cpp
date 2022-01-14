#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    cout << "Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal_106.cpp" << endl;
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

TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ri = hm[postorder[pe]];
        TreeNode* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        TreeNode* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size())
            return NULL;
    map<int,int> hm;
    for (int i=0;i<inorder.size();++i)
        hm[inorder[i]] = i;
    return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                            postorder.size()-1,hm);
}