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
class TreeNode{

    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

void convertBSTTOInorder(TreeNode<int>* root, vector<int> &list)
{
    if (root == NULL) return;

    convertBSTTOInorder(root->left, list);
    list.push_back(root->data);
    convertBSTTOInorder(root->right, list);
}

vector<int> mergeTwosortedLinkedvector(vector<int> &list1, vector<int> &list2)
{
    vector<int> ans;
    int n = list1.size();
    int m = list2.size();
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (list1[i] < list2[j])
        {
            ans.push_back(list1[i]);
            i++;
        }
        else
        {
            ans.push_back(list2[j]);
            j++;
        }
    }

    while (i < n)
    {
        ans.push_back(list1[i]);
        i++;
    }

    while (j < m)
    {
        ans.push_back(list2[j]);
        j++;
    }

    return ans;
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

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> list1;
    vector<int> list2;

    // step 1
    convertBSTTOInorder(root1, list1);
    convertBSTTOInorder(root2, list2);

    // step 2
    // merge two sorted linkedvector
    vector<int> ans = mergeTwosortedLinkedvector(list1, list2);

    // step 3
    // inorder to Balanced BST
    return inorderToBST(0, ans.size() - 1, ans);
}