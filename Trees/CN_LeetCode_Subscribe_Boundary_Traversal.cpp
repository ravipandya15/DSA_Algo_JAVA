#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// getting wrong answer
// check java or C# Code -> both are correct
int main()
{
    cout << "CN_LeetCode_Subscribe_Boundary_Traversal" << endl;
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

bool isLeaf(TreeNode<int>* node)
{
    return (node->left == NULL) && (node->right == NULL);
}

void addLeftBoundry(TreeNode<int>* node, vector<int> res)
{
    TreeNode<int>* cur = node->left;
    while (cur != NULL)
    {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left != NULL) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaf(TreeNode<int>* node, vector<int> res)
{
    if (isLeaf(node)) res.push_back(node->data);

    if (node->left != NULL) addLeaf(node->left, res);
    if (node->right != NULL) addLeaf(node->right, res);
}

void addRightBoundry(TreeNode<int>* node, vector<int> res)
{
    TreeNode<int>* cur = node->right;
    vector<int> temp;
    while (cur != NULL)
    {
        if (!isLeaf(cur)) temp.push_back(cur->data);
        if (cur->right != NULL) cur = cur->right;
        else cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if (root == NULL) return res;
    if (!isLeaf(root)) res.push_back(root->data);

    addLeftBoundry(root, res);
    addLeaf(root, res);
    addRightBoundry(root, res);
    return res;
}