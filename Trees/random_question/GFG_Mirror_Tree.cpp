#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;
    
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        mirror(node->left);
        mirror(node->right);
    }
};