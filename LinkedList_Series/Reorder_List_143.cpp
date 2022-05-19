#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMiddle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseLinkedList(ListNode* node)
{
    ListNode* prev = NULL;
    ListNode* curr = node;
    ListNode* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* mergeTwoLinkedList(ListNode* head1, ListNode* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    ListNode* resultNode = head1;

    // only head2 != null will also work as list2 length is same or 1 less than list1
    while (head1 != NULL && head2 != NULL)
    {
        ListNode* next1 = head1->next;
        ListNode* next2 = head2->next;
        head1->next = head2;
        head2->next = next1;
        head1 = next1;
        head2 = next2;
    }

    return resultNode;
}

void reorderList(ListNode* head) {
    if (head == NULL) return;

    ListNode* middle = findMiddle(head);
    ListNode* head2 = middle->next;
    middle->next = NULL;

    head2 = reverseLinkedList(head2);
    head = mergeTwoLinkedList(head, head2);
} 