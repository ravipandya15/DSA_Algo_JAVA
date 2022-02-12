#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* findMid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node* mergeSortedList(node* left, node* right)
{
    if (left == NULL) return right;
    if (right == NULL) return left;

    node* ans = new node(-1);
    node* temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left; // or temp = temp->next
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left != NULL)
    {
        temp->next = left;
    }
    else if (right != NULL)
    {
        temp->next = right;
    }

    return ans->next;
}

node* mergeSort(node *head) {
    if (head == NULL || head->next == NULL) return head;

    // find mid;
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // recursively sort left and right part
    left = mergeSort(left);
    right = mergeSort(right);

    // merge sorted List
    node* result = mergeSortedList(left, right);

    return result;
}