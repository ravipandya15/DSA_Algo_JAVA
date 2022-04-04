#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

Node* mergeTwoSortedList(Node* a, Node* b)
{
    Node* ans = new Node(-1);
    Node* temp = ans;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a != NULL) temp->bottom = a;
    else temp->bottom = b;

    return ans->bottom;
}

Node *flatten(Node *root)
{
   if (root == NULL || root->next == NULL)
   {
       return root;
   }

   root->next = flatten(root->next);
   Node* result = mergeTwoSortedList(root, root->next);
   return result;
}