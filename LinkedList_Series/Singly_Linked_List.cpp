#include<iostream>
#include<vector>
using namespace std;

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(12, head);
    print(head);

    insertAtHead(15, head);
    print(head);

    insertAtTail(20,  tail);
    print(head);

    insertAtPosition(1, 50,  head,  tail);
    print(head);

    insertAtPosition(6, 60,  head,  tail);
    print(head);

    insertAtPosition(3, 100,  head,  tail);
    print(head);

    insertAtPosition(9, 100,  head,  tail);
    print(head);

    insertAtPosition(19, 100,  head,  tail);
    print(head);

    //deleteNode_At_Position(1,  head,  tail);
    //print(head);

    //deleteNode_At_Position(7,  head,  tail);
    //print(head);

    //deleteNode_At_Position(5,  head,  tail);
    //print(head);

    //deleteNode_By_Value(10,  head,  tail);
    //print(head);

    //deleteNode_By_Value(50,  head,  tail);
    //print(head);

    //deleteNode_By_Value(60,  head,  tail);
    //print(head);

    cout << "head is " << head->data << " tail is " << tail->data << endl;
    return 0;
}

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

void insertAtHead(int data, Node* &head)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int position, int data,  Node* &head,  Node* &tail)
{
    if (position == 1)
    {
        insertAtHead(data,  head);
        return;
    }

    int count = 1;
    Node* temp = head;

    while (count < position - 1)
    {
        if (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        else
        {
            return;
        }
    }

    if (temp != NULL && temp->next == NULL)
    {
        insertAtTail(data,  tail);
        return;
    }
    else
    {
        if (temp == NULL) return;
    }
        

    // insert at middle
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void insertAtTail(int data,  Node* &tail)
{
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Deleting Node by Position
void deleteNode_At_Position(int position, Node* &head, Node* &tail)
{
    if (position == 1)
    {// delete 1st Node
        Node* cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
    else
    {// deleting middle or last node
        int count = 1;
        Node* prev = NULL;
        Node* cur = head;
        while (count < position)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }

        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
        if (prev->next == NULL)
            tail = prev;
    }
}

// Delete Node by value
void deleteNode_By_Value(int value, Node* &head, Node* &tail)
{
    int count = 1;
    Node* cur = head;
    Node* prev = NULL;
    while (cur->data != value)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }

    if (count == 1)
    {// deleting 1st Node
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
    else
    {
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
        if (prev->next == NULL)
            tail = prev;
    }
}

void print(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }

    cout << endl;
}