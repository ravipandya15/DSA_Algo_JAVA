#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// 23. Merge k Sorted Lists

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class Compare
{
    public:
    bool operator()(Node<int>* n1, Node<int>* n2)
    {
        return n2->data < n1->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*, vector<Node<int>*>, Compare> mini;

    int k = listArray.size();

    if (k == 0) return NULL;

    // step 1:
    for(int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            mini.push(listArray[i]);
        }
    }

    // step 2:

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while (!mini.empty())
    {
        Node<int>* top = mini.top();
        mini.pop();

        if (top->next != NULL)
        {
            mini.push(top->next);
        }

        if (head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}