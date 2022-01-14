#include<iostream>
#include<vector>
#include<queue>
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL) q.push(node-> left);
            if (node-> right != NULL) q.push(node->right);
            temp.push_back(node->val);
        }
        result.push_back(temp);
    }

    return result;
}