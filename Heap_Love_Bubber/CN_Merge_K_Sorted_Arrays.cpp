#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

class Node
{
    public:
        int data;
        int row;
        int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare
{
    public:
    bool operator()(Node* n1, Node* n2)
    {
        return n2->data < n1->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, Compare> mini;

    // step1 : insert 1st element of every k array
    for (int i = 0; i < k; i++)
    {
        Node* temp = new Node(kArrays[i][0], i, 0);
        mini.push(temp);
    }

    // step 2:
    while (mini.size() > 0) // or !mini.empty()
    {
        Node* cur = mini.top();
        mini.pop();

        ans.push_back(cur->data);

        int curRow = cur->row;
        int curCol = cur->col;

        if (curCol + 1 < kArrays[curRow].size())
        {
            Node* next = new Node(kArrays[curRow][curCol + 1], curRow, curCol + 1);
            mini.push(next);
        }
    }

    return ans;
}
