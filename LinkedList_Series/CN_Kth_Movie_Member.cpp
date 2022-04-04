#include<iostream>
#include<vector>
using namespace std;

class List {
public:
    int data;
    List *next;
    List() {};
    List(int v){
        data = v;
        next = NULL;
    };
};

int kthMoney(List *head , int k) {
    
    List* temp = head;
    while (k > 0)
    {
        k--;
        temp = temp->next;
    }

    while (temp != NULL)
    {
        temp = temp->next;
        head = head->next;
    }

    return head->data;
}

int main()
{
    return 0;
    // 4 5 3 1 2 6 -1
    List *head = new List(4);
    List *next2 = new List(5);
    List *next3 = new List(3);
    List *next4 = new List(1);
    List *next5 = new List(2);
    List *next6 = new List(6);
    List *next7 = new List(-1);

    head->next = next2;
    next2->next = next3;
    next3->next = next4;
    next4->next = next5;
    next5->next = next6;
    next6->next = next7;

    int k = 3;
    int ans = kthMoney(head, k);
    cout << "ans is " << ans << endl;
}

