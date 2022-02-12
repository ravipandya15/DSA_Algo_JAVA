#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* merge(Node* down, Node* right)
{
    Node* ans= new Node(-1);
    Node* temp = ans;

    while (down != NULL && right != NULL)
    {
        if (down->data < right->data)
        {
            temp->next = down;
            temp = temp->next;
            down = down->child;
            temp->child = NULL;
        }
        else
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }

    while (down != NULL)
    {
        temp->next = down;
        temp = temp->next;
        down = down->child;
        temp->child = NULL;
    }

    while (right != NULL)
    {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }

    return ans->next;
}

Node* flattenLinkedList(Node* head) 
{
	if (head == NULL) return head;

    Node* down = head;

    Node* right = flattenLinkedList(head->next);

    Node* result = merge(down, right);

    return result;
}

int main()
{
    Node* head = new Node(3);
    Node* next2 = new Node(5);
    Node* next3 = new Node(22);
    Node* next4 = new Node(26);
    Node* next5= new Node(39);

    Node* down1= new Node(4);
    Node* down2= new Node(6);
    Node* down3= new Node(11);
    Node* down4= new Node(14);
    Node* down5= new Node(25);
    Node* down6= new Node(28);

    head->next = next2;
    next2->next = next3;
    next3->next = next4;
    next4->next = next5;

    head->child = down1;
    down1->child = down2;

    next2->child = down3;
    down3->child = down4;

    next3->child = down5;

    next4->child = down6;

    Node* result = flattenLinkedList(head);

    while (result != NULL)
    {
        cout << result->data << " " << endl;
        result = result->next;
    }

    return 0;
}

