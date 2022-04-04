#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int countNodes(struct Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// to check if it is complete Binary tree or not
bool isCBT(struct Node* root, int index, int count)
{
    if (root == NULL) return true;

    if (index >= count) return false;

    return isCBT(root->left, 2 * index + 1, count) && isCBT(root->right, 2 * index + 2, count);
}

bool isMaxOrder(struct Node* root)
{
    if (root == NULL) return true;

    // left Node
    if (root->left == NULL && root->right == NULL) return true;

    // only left child exist
    if (root->right == NULL)
    {
        return ( (root->data > root->left->data) && isMaxOrder(root->left) );
    }
    else
    {
        return ( (root->data > root->left->data) && (root->data > root->right->data) 
                && isMaxOrder(root->left)  && isMaxOrder(root->right));
    }
}

bool isHeap(struct Node* tree) {
    int index = 0;
    int count = countNodes(tree);

    return (isCBT(tree, index, count) && isMaxOrder(tree));
}

