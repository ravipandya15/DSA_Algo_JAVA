#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Level Order" << endl;
    return 0;
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {}
};

void AllTraversal(TreeNode* root)
{
    vector<int> pre, in, post;
    if (root == NULL) return;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        // pair<TreeNode*, int> it = st.top();
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
}