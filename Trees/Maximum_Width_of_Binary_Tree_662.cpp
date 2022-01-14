#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "Maximum_Width_of_Binary_Tree_662" << endl;
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

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int ans = 0;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int min_level_index = q.front().second;
            int first = 0, last = 0;
            for (int i = 0; i < size; i++)
            {
                int cur_index = q.front().second - min_level_index;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur_index;
                if (i == size - 1) last = cur_index;
                if (node->left != NULL) q.push({node->left, cur_index * 2 + 1});
                if (node->right != NULL) q.push({node->right, cur_index * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
    return ans;        
}