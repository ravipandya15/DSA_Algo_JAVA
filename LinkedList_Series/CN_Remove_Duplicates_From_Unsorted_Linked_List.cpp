#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Not Working
// Getting runtime error (SIGSEGV)

int  main()
{
    return 0;
}

class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node *removeDuplicates(Node *head)
{
    if (head == NULL) return NULL;

    map<int, bool> map;
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL)
    {
        if (map.find(cur->data) == map.end()) // check this it should be != map.end()
        {
            prev->next = cur->next;
            Node* nodeToDelete = cur;
            cur = cur->next;
            nodeToDelete->next = NULL;
            delete(nodeToDelete);
        }
        else
        {
            map[cur->data] = true;
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}