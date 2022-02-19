#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

struct Node
{
    int data;
    Node* left, * right;
}; 

int solve(Node* root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->data;

    int left = solve(root->left);
    if (left == -1) return -1;
    int right = solve(root->right);
    if (right == -1) return -1;

    if (root->data != (left + right)) return -1;

    return root->data + left + right;
}

bool isSumTree(Node* root)
{
    return solve(root) != -1;
}