#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    cout << "Level Order" << endl;
    return 0;
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {}
};

// TC -> O(N)
// SC -> O(N)
 vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;
    stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty())
    {
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);

        if (node->right != NULL)
        {
            stack.push(node->right);
        }
        if (node->left != NULL)
        {
            stack.push(node->left);
        }
    }
    return result;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inOrder;
    stack<TreeNode*> stack;
    TreeNode* node = root;

    while(true)
    {
        if (node !=  NULL)
        {
            stack.push(node);
            node = node->left;
        }
        else{
            if (stack.empty()) break;
            node = stack.top();
            stack.pop();
            inOrder.push_back(node->val);
            node = node->right;
        }
    }
    return inOrder;
}

//using 2 Stack
vector<int> postorderTraversal_1(TreeNode* root) {
    // iterative way
    // using 2 stack
    vector<int> postOrder;
    if (root == NULL) return postOrder;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);

    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != NULL) st1.push(root->left);
        if (root->right != NULL) st1.push(root->right);
    }

    while (!st2.empty())
    {
        postOrder.push_back(st2.top()->val);
        st2.pop();
    }

    return postOrder;
}

// TLE mare chhe -> Check SDE Cheet or Free ka Tree Series Code
 //using 1 Stack
vector<int> postorderTraversal_2(TreeNode* root) {
    //iterative approach
    // using 1 stack
    vector<int> postOrder;
    if (root == NULL) return postOrder;
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    while ( cur != NULL || !stack.empty())
    {
        if (cur != NULL)
        {
            stack.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode* temp = stack.top()->right;
            if (temp == NULL)
            {
                temp = stack.top();
                stack.pop();
                postOrder.push_back(temp->val);
                if (!stack.empty() && temp == stack.top()->right)
                {
                    temp = stack.top();
                    stack.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
    return postOrder;
}