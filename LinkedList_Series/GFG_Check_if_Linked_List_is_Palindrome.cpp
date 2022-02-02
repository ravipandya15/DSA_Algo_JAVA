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
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool checkPalindromw(vector<int> arr)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
            return false;

        s++;
        e--;
    }

    return true;
}
// 1st solution
// TC -> O(N)
// SC -> O(N)
bool isPalindrome1(Node* head)
{
    if (head == NULL || head->next == NULL) return true;
    vector<int> list;
    Node* temp = head;
    while (temp != NULL)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    // check list is palindromw or not
    return checkPalindromw(list);
}
Node* findMiddle(Node* node)
{
    Node* slow = node;
    Node* fast = node->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node* reverse(Node* node)
{
    Node* cur = node;
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

// 2nd solution - > Optimal
// TC -> O(N)
// SC -> O(1)
bool isPalindrome2(Node* head)
{
    if (head == NULL || head->next == NULL) return true;

    // find middle
    Node* middle = findMiddle(head);

    middle->next = reverse(middle->next);

    Node* head1 = head;
    Node* head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    // again reverse remaining part so actual linked vector remains as it is.
    middle->next = reverse(middle->next);

    return true;
}