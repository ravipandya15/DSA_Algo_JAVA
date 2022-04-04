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

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred = -1;
    int successor = -1;
    BinaryTreeNode<int>* cur = root;
    // find node
    while (cur->data != key)
    {
        if (key < cur->data)
        {
            successor = cur->data;
            cur = cur->left;
        }
        else if (key > cur->data)
        {
            pred = cur->data;
            cur = cur->right;
        }
    }

    // found key
    // find max node from left sub tree
    BinaryTreeNode<int>* leftTree = cur->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // find min. node from right sub tree
    BinaryTreeNode<int>* rightTree = cur->right;
    while (rightTree != NULL)
    {
        successor = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> result = make_pair(pred, successor);

    return result;
}

struct Node
{
	int key;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pred, Node*& successor, int key)
{
    Node* cur = root;
    // find node
    while (cur->key != key)
    {
        if (key < cur->key)
        {
            successor = cur;
            cur = cur->left;
        }
        else if (key > cur->key)
        {
            pred = cur;
            cur = cur->right;
        }
    }

    // found key
    // find max node from left sub tree
    Node* leftTree = cur->left;
    while (leftTree != NULL)
    {
        pred = leftTree;
        leftTree = leftTree->right;
    }

    // find min. node from right sub tree
    Node* rightTree = cur->right;
    while (rightTree != NULL)
    {
        successor = rightTree;
        rightTree = rightTree->left;
    }
}