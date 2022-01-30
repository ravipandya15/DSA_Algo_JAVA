#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int _d)
    {
        this->data = _d;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "memory is free for node with data" << value << endl;
    }
};

int main()
{
    return 0;
}

// Floyd's Cycle delection Algo -> using 2 pointer approach
// TC -> O(N)
// SC -> O(1)
Node* floydDetectCycle(Node* head)
{
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
            return slow;
    }

    return NULL;
}

Node* getStartingNodeOfLoop(Node* head)
{
    if (head == NULL) return NULL;

    Node* intersactionNode = floydDetectCycle(head);
    if (intersactionNode == NULL) return NULL;

    Node* slow = head;

    while (slow != intersactionNode)
    {
        slow = slow->next;
        intersactionNode = intersactionNode->next;
    }

    return slow;
}

Node* removeLoop(Node* head) {

    if (head == NULL) return NULL;

    Node* startingOfLoop = getStartingNodeOfLoop(head);

    if (startingOfLoop == NULL) return head;

    Node* temp = startingOfLoop;
    while (temp->next != startingOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}