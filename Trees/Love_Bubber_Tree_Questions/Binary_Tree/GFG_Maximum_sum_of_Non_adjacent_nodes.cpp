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

pair<int, int> solve(Node* root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> ans;
    // include current node
    ans.first = root->data + left.second + right.second;

    // exclude current Node
    ans.second = max(left.first, left.second) + max(right.first, right.second);

    return ans;
}

int getMaxSum(Node *root) 
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}