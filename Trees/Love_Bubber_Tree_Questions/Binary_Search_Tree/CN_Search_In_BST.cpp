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
class BinaryTreeNode {
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

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }
        if (x < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}