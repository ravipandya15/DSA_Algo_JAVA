#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Path to given node" << endl;
    return 0;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 


class Solution
{
    bool Solution::getPath(TreeNode* node, int B, vector<int> res)
    {
        if (node == NULL) return false;

        res.push_back(node->val);

        if (node->val == B) return true;

        if (getPath(node->left, B, res) || getPath(node->right, B, res)) return true;

        res.pop_back();

        return false;
    }

    vector<int> Solution::solve(TreeNode* A, int B) {
        vector<int> res;
        if (A == NULL) return res;
        getPath(A, B, res);
        return res;
    }
};
