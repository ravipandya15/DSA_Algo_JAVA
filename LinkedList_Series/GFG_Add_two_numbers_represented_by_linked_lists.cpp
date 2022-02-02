#include<iostream>
#include<vector>
#include<map>
using namespace std;

int  main()
{
    return 0;
}
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    Node* reverse(Node* head)
    {
        Node* cur = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    private:
    void insertAtTail(Node* &head, Node* &tail, int data)
    {
        Node* temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    private:
    Node* add(Node* first, Node* second)
    {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int sum = 0;
            if (first != NULL)
                sum += first->data;

            if (second != NULL)
                sum += second->data;

            sum += carry;

            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;

            if (first != NULL)
                first = first->next;

            if (second != NULL)
                second = second->next;
        }

        return ansHead;
    }

    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
            // step 1: reverse both linked List
            Node* newFirst = reverse(first);
            Node* newSecond = reverse(second);

            // add numbers from both linkedList
            Node* result = add(newFirst, newSecond);

            // reverse resultant Linked List
            Node* newResult = reverse(result);

            // reverse first and second linkedList again
            Node* oldfirst = reverse(newFirst);
            Node* oldsecond = reverse(newSecond);

            return newResult;
    }
};