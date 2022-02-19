#include<iostream>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

class Queue {
    int* arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (qfront == rear);
    }

    void enqueue(int data) {
        // check if queue is full or not
        if (rear == size) return;

        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (qfront == rear) return -1;
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int front() {
        if (qfront == rear) return -1;
        return arr[qfront];
    }
};