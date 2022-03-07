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
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root,int k, int &count, vector<int> list)
{
    if (root == NULL) return;

    list.push_back(root->data);

    solve(root->left, k, count, list);
    solve(root->right, k, count, list);

    int sum = 0;
    int size = list.size();
    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + list[i];
        if (sum == k)
            count++;
    }

    list.pop_back();
}

int sumK(Node *root,int k)
{
    vector<int> list;
    int count = 0;
    solve(root, k, count, list);
    return count;
}