#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Floor_in_BST.cpp" << endl;
    return 0;
}

template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    while (root != NULL)
    {
        if (root->val == X)
        {
            floor = root->val;
            return floor;
        }
        if (X < root->val)
        { // left side
            root = root->left;
        }
        else
        {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}