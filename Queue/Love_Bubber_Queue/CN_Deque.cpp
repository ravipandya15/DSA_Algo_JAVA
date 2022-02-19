#include<iostream>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

class Deque
{
public:
    int* arr;
    int front;
    int rear;
    int size;
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check queue is full or not
        if (isFull())
        {
            return false;
        }

        if (front == -1)
        {// firt element
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {// circular check
            front = size - 1;
        }
        else
        {// normal flow
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // check queue is full or not
        if (isFull())
        {
            return false;
        }

        if (front == -1)
        {// firt element
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {// circular check
            rear = 0;
        }
        else
        {// normal flow
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty()) return -1;

        int data = arr[front];
        arr[front] = -1;

        if (front == rear)
        {// single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {// circular flow
            front = 0;
        }
        else
        {// normal flow
            front++;
        }

        return data;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty()) return -1;

        int data = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {// single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {// circular flow
            rear = size -1;
        }
        else
        {// normal flow
            rear--;
        }

        return data;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};