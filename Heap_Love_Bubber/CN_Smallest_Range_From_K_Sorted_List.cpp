#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
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

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // step 1
    for (int i = 0; i < k; i++)
    {
        pq.push(new Node(a[i][0], i, 0));
        mini = min(mini, a[i][0]);
        maxi = max(maxi, a[i][0]);
    }

    int start = mini, end = maxi;

    // step 2
    while (!pq.empty())
    {
        Node* top = pq.top();
        pq.pop();

        mini = top->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (top->col + 1 < n)
        {
            maxi = max(maxi, a[top->row][top->col + 1]);
            pq.push(new Node(a[top->row][top->col + 1], top->row, top->col + 1));
        }
        else
        {
            break;
        }
    }

    return (end - start + 1);
}