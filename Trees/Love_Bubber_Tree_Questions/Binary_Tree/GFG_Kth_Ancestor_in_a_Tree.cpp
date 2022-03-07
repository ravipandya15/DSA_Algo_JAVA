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
	struct Node *left, *right;
};

Node* solve(Node* root, int &k, int node)
{
    // base case
    if (root == NULL) return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            // to lock the answer -> edge case
            k = INT_MAX;
            return root;
        }
        return left;
    }

    if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            // to lock the answer -> edge case
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else
    {
        // both NULL .   -> both non - NULL case never comes
        return NULL;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)  //ans->data == node -> edge case
    {
        return -1;
    }
    return ans->data;
}