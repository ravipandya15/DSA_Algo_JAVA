#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Flatten_Binary_Tree_to_Linked_List_114.cpp" << endl;
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

class Solution
{
public:
    // Approach - 1
    // Recursive
    // TC -> O(N), SC -> O(N)
    TreeNode* prev = NULL;
    void flatten1(TreeNode* root) {
        // Approach - 1
        // Recursive
        // TC -> O(N), SC -> O(N)
        if (root == NULL) return;

        flatten1(root->right);
        flatten1(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;   
    }

    // Approach -2 
    // Iterative
    // TC -> O(N), SC -> O(N)
    void flatten2(TreeNode* root) {
        // Approach -2 
        // Iterative
        // TC -> O(N), SC -> O(N)
        if (root == NULL) return;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();

            if (cur->right != NULL) st.push(cur->right);
            if (cur->left != NULL) st.push(cur->left);

            if (!st.empty()) cur->right = st.top();
            cur->left = NULL;
        }   
    }

    // Approach - 3 
    // Morris Traversal
    // TC -> O(N), SC -> O(1)
    void flatten3_Morris_Traversal(TreeNode* root) {
        // Approach - 3 
        // Morris Traversal
        // TC -> O(N), SC -> O(1)
        while (root != NULL)
        {
            if (root->left != NULL)
            {
                TreeNode* prev = root->left;
                while (prev->right != NULL) prev = prev->right;

                prev->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }    
    }
};