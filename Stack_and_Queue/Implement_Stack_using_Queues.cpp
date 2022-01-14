// Implement_Stack_using_Queues
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    cout << "225. Implement Stack using Queues";
    MyStack* obj = new MyStack();
    obj->Push(1);
    obj->Push(2);
    int param_2 = obj->Top();
    int param_5 = obj->Pop();
    //int param_3 = obj.Top();
    bool param_4 = obj->Empty();
    return 0;
}
class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {

    }

    // using 1 queue
    void Push(int x)
    {
        q1.push(x);
        for (int i = 0; i < q1.size() - 1; i++)
        {
            //q1.Enqueue(q1.Dequeue());
            q1.push(q1.front());
            q1.pop();
        }
    }

    // using 2 queue
    // void Push1(int x)
    // {
    //     queue<int> q2;
    //     q2.push(x);
    //     while (!q1.empty())
    //     {
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     q1 = q2;
    // }

    int Pop()
    {
        int temp = q1.front();
        q1.pop(); 
        return temp;
    }

    int Top()
    {
        return q1.front();
    }

    bool Empty()
    {
        return q1.empty();
    }
};