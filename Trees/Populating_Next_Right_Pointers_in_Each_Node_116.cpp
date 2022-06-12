#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    // base case
    if (root == NULL) return root;

    Node* curr = root;

    while (curr->left != NULL)
    {
        Node* temp = curr;

        while (curr != NULL)
        {
            curr->left->next = curr->right;
            if (curr->next != NULL)
            {
                // as given perfact binary tree so every parent contains 2 child (except leaf nodes) 
                //-> so we don't need to write (curr.right != null)
                // all leaf nodes are on same level
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }

        curr = temp->left;
    }
    return root;
}