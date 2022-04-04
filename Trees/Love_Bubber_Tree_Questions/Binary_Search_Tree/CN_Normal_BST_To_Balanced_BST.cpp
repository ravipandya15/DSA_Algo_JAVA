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
class TreeNode
{
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
        if (left)
            delete left;
        if (right)
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

TreeNode<int>* inorderToBST(int s, int e, vector<int> &inOrder)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(inOrder[mid]);
    root->left = inorderToBST(s, mid - 1, inOrder);
    root->right = inorderToBST(mid + 1, e, inOrder);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inOrder;
    InOrderTraversal(root, inOrder);

    return inorderToBST(0, inOrder.size() - 1, inOrder);
}