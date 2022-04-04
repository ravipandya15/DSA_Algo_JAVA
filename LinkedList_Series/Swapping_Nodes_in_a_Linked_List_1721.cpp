#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// also do for swapping Nodes -> InPlace

// swapping values
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* cur = head;
        int kk = k;
        while (kk - 1 > 0)
        {
            kk--;
            cur = cur->next;
        }

        ListNode* first = cur;
        ListNode* last = head;

        while (cur->next != NULL)
        {
            last = last->next;
            cur = cur->next;
        }
        int temp = first->val;
        first->val = last->val;
        last->val = temp;

        return head;
    }
};