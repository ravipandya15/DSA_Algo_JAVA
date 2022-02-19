#include<iostream>
#include<vector>
using namespace std;

class List {
      public:
          int data;
          List *next;

          List(int val) {
              this->data = val;
              next = NULL;
          }
          ~List() {
              if (next != NULL) {
                  delete next;
              }
          }
   };
List* reverse(List* head2)
{
    if (head2 == NULL) return head2;

    List* cur = head2;
    List* prev = NULL;
    List* next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

List* foldAndMerge(List *head) {

   if (head->data == -1) return head;

    List* temp = head;
    List* temp2 = NULL;
    while (temp->data != -1)
    {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = NULL;

    List* slow = head;
    List* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    List* head2 = slow->next;
    slow->next = NULL;

    head = reverse(head);

    List* cur = head2;
    List* prev = NULL;

    while (cur != NULL)
    {
        cur->data = cur->data * head->data;
        prev = cur;
        cur = cur->next;
        head = head->next;
    }

    prev->next = new List(-1);

    return head2;
}