#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void InOrderTraversal(TreeNode<int>* root, vector<int> &inOrder)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->data);
    InOrderTraversal(root->right, inOrder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
     // min. ek node to hase j
    // as N >= 1
    vector<int> inOrder;
    InOrderTraversal(root, inOrder);

    TreeNode<int>* newNode = new TreeNode<int>(inOrder[0]);
    TreeNode<int>* cur = newNode;

    for (int i = 1; i < inOrder.size(); i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(inOrder[i]);
        cur->left = NULL;
        cur->right = temp;
        cur = temp;
    }

    // for last node
    cur->left = NULL;
    cur->right = NULL;
    return newNode;
}