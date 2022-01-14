#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Ceil_from_BST.cpp" << endl;
    return 0;
}

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;
    while (node != NULL)
    {
        if (node->data == x)
        {
            ceil = node->data;
            return ceil;
        }
        if (x < node->data)
        { // left side
            ceil = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return ceil;
}