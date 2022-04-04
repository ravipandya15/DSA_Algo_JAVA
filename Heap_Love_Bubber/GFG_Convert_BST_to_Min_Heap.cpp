#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

struct Node
{
    int data;
    Node *left, *right;
};

void inorderTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL) return;

    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

// preorder traversal
void BSTTToMinHeap(Node *root, vector<int> &ans, int &index)
{
    if (root == NULL) return;

    root->data = ans[index++];
    BSTTToMinHeap(root->left, ans, index);
    BSTTToMinHeap(root->right, ans, index);
}

void convertToMinHeapUtil(Node *root)
{
    vector<int> ans;
    int index = 0;

    inorderTraversal(root, ans);

    BSTTToMinHeap(root, ans, index);
}