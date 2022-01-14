#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    cout << "Level Order" << endl;
    return 0;
}

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (root == NULL) return "";
    string res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if (node == NULL)
        {
            res.append("#,");
            continue;
        }
        res.append(to_string(node->val) + ',');
        q.push(node->left);
        q.push(node->right);
    }
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
            
        }
        else
        {
            TreeNode* left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            TreeNode* right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
    }
    return root;
}