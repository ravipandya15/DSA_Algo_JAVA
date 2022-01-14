#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    cout << "All_Nodes_Distance_K_in_Binary_Tree_863" << endl;
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

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != NULL)
        {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track);
    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;
    q.push(target);
    visited[target] = true;
    int dis = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (dis == k) break;
        dis++;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL && visited[node->left] == NULL)
            {
                q.push(node->left);
                visited[node->left] = true;
            }
            if (node->right != NULL && visited[node->right] == NULL)
            {
                q.push(node->right);
                visited[node->right] = true;
            }
            // check parent node
            if (parent_track[node] != NULL && visited[parent_track[node]] == NULL)
            {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        res.push_back(node->val);
    }
    return res;
}