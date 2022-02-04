#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int  main()
{
    return 0;
}



struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    private:
    static void insertAtTail(Node* &head, Node* &tail, int data)
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // TC -> O(N)
    // SC -> O(N)
    public:
    Node *copyList1(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // use of HashMap
        unordered_map<Node*, Node*> map;
        temp = head;
        Node* temp2 = cloneHead;
        while (temp != NULL)
        {
            map[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }

        temp = head;
        temp2 = cloneHead;
        while (temp != NULL)
        {
            temp2->arb = map[temp->arb];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return cloneHead;
    }

    Node *copyList2(Node *head)
    {
        // step 1 -> clone original list (with help of next pointer)
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        // step 2 -> cloneNodes add inbetween original linkedList
        while (originalNode != NULL && cloneNode != NULL)
        {
            // next is commonly used for both originalNode and cloneNode
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        // step 3 -> set Random pointer
        while (originalNode != NULL)
        {
            if (originalNode->arb != NULL)
            {
                originalNode->next->arb = originalNode->arb->next;
            }
            originalNode = originalNode->next->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        // step 4 -> revert changes done in step2
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }
            
            cloneNode = cloneNode->next;
        }

        // step 5 -> return ans
        return cloneHead;
    }
};
