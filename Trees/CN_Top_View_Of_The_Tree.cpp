#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    // Not working check Java Code 
    cout << "Top View of Binary Tree" << endl;
    return 0;
}

template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

// Not working check Java Code 
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> res;
    if (root == NULL) return res;
    queue<pair<TreeNode<int>*, int>> queue;
    map<int, int> map;

    queue.push({root, 0});

    while (!queue.empty())
    {
        auto it = queue.front();
        queue.pop();

        TreeNode<int>* node = it.first;
        int line = it.second;

        if (map.find(line) == map.end()) 
        {
            map[line] = node->val;
        }

        if (node->left != NULL)
        {
            queue.push({node->left, line -1});
        }
        if (node->right != NULL)
        {
            queue.push({node->left, line +1});
        }
    }

    for (auto it : map)
    {
        res.push_back(it.second);
    }

    return res;
}