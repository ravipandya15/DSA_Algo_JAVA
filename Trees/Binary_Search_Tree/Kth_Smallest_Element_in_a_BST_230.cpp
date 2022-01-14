#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Kth_Smallest_Element_in_a_BST_230.cpp" << endl;
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

int morris_kthSmallest(TreeNode* root, int k) {
    //Morris Traversal
    TreeNode* cur = root;
    int count = 0;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            count++;
            if (count == k) return cur->val;
            cur = cur->right;
        }
        else
        {
            TreeNode* prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (count == k) return cur->val;
                cur = cur->right;
            }
        }
    }
    return -1;
}

void inOrder(TreeNode* root, int k, int count, vector<int> ans)
{
    if (root == NULL) return;

    inOrder(root->left, k, count, ans);
    ans.push_back(root->val);
    inOrder(root->right, k, count, ans);
}

int kthSmallest1(TreeNode* root, int k) {
    //Recursion
    vector<int> ans;
    inOrder(root, k, 0, ans);
    return ans[k-1];
}

int kthSmallest2(TreeNode* root, int k) {
     //Iterative
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* node = root;
    int count = 0;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty()) break;
            node = st.top();
            st.pop();

            count++;
            if (count == k) return node->val;

            node = node->right;
        }
    }
    return -1;   
}