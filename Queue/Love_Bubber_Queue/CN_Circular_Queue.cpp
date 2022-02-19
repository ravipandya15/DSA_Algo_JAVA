#include<iostream>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if ((front == 0 && rear == size -1) || (rear == front-1))
        {
            // queue is full
            return false;
        }
        else if (front == -1) // first element to push
        {
            front = rear = 0;
        }
        else if (rear == size-1 && front != 0)
        { // to maintian cyclic nature
            rear = 0;
        }
        else
        {// normal flow
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if (front == -1)
        {
            // queue is empty;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) // single element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {// to maintian cyclic nature
            front = 0;
        }
        else
        {// normal flow
            front++;
        }
        return ans;
    }
};