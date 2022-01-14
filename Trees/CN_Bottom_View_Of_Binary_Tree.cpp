#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    cout << "Top View of Binary Tree" << endl;
    return 0;
}

template <typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

// Not working check Java Code 
vector<int> bottomView(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<int> res;
    if (root == NULL) return res;
    queue<pair<BinaryTreeNode<int>*, int>> queue;
    map<int, int> map;

    queue.push({root, 0});

    while (!queue.empty())
    {
        auto it = queue.front();
        queue.pop();

        BinaryTreeNode<int>* node = it.first;
        int line = it.second;

        map[line] = node->data;

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