#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

class NQueue
{
    public:
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;

    NQueue(int n, int k)
    {
        arr = new int[n];
        next = new int[n];

        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;

        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        freespot = 0;
    }

    void enqueue(int data, int qn)
    {
        // check overflow condition
        if (freespot == -1)
        {
            cout << "Overflow" << endl;
            return;
        }

        // find index;
        int index = freespot;
        freespot = next[index];

        // if first element
        if (front[qn-1] == -1)
        {
            front[qn-1] = index;
        }
        else
        {// not first element
            next[rear[qn-1]] = index;
        }

        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        // check inderflow condition
        if (front[qn-1] == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        // find index;
        int index = front[qn-1];
        front[qn-1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};