#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


// check once
// this solution is not working
// same solution as Valide BST or not

int main()
{
    return 0;
}
template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

pair<pair<int,int>,int> solve(TreeNode < int > * root)
{
    // base case
    if (root == NULL)
    {
        pair<pair<int,int>,int> p = make_pair(make_pair(INT_MAX, INT_MIN), 1);
    }
    
    pair<pair<int,int>,int> left = solve(root->left);
    pair<pair<int,int>,int> right = solve(root->right);
    
    if (left.first.second < root->data && right.first.first > root->data)
    {
        return make_pair(make_pair(min(left.first.first, root->data), max(right.first.second, root->data)), 1);
    }
    return make_pair(make_pair(INT_MIN, INT_MAX), 0);
}

int validGame(TreeNode < int > * root) {
   pair<pair<int,int>,int> p = solve(root);
   return p.second;
}

