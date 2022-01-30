#include<iostream>
#include<vector>
using namespace std;

int  main()
{
    return 0;
}

class Node 
{
    public:
    int data;
    Node* next;

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
    }
};

Node * uniqueSortedList(Node * head) {
    if (head == NULL) return NULL;

    Node* cur = head;
    while (cur != NULL)
    {
        if (cur->next != NULL && cur->data == cur->next->data)
        {
            Node* next_next = cur->next->next;
            Node* nodeToDetete = cur->next;
            cur->next = next_next;
            nodeToDetete->next = NULL;
            delete(nodeToDetete);
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}