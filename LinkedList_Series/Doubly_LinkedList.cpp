#include<iostream>
#include<vector>
using namespace std;

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;

    printLinkedList(head);
    int length = lengthOfLinkedList(head);
    cout << "length of linkedList is " << length << endl;

    return 0;
}

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int _d)
    {
        this->data = _d;
        this->next = NULL;
        this->prev = NULL;
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

void printLinkedList(Node* &head)
{
    Node* cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// gives Length of LinkedList
int lengthOfLinkedList(Node* &head)
{
    int count = 0;
    Node* cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}