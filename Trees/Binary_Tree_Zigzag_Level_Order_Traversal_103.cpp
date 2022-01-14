#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    cout << "103. Binary Tree Zigzag Level Order Traversal" << endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<TreeNode*> queue;
        queue.push(root);
        bool leftToRight = true;

        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> tempList(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = queue.front();
                queue.pop();
                int index = (leftToRight) ? i : size - 1 - i;
                tempList[index] = temp->val; 

                if (temp->left != NULL) queue.push(temp->left);
                if (temp->right != NULL) queue.push(temp->right);
            }
            result.push_back(tempList);
            leftToRight = !leftToRight;
        }
        return result;
}

