#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "225. Implement Stack using Queues";
    MyQueue* obj = new MyQueue();
    obj->push(2);
    obj->push(5);
    obj->push(3);
    int o1 = obj->peek();
    int o2 = obj->pop();
    obj->push(6);
    int o3 = obj->pop();
    int o4 = obj->pop();
    int o5 = obj->peek();
    bool o6 = obj->empty();
    return 0;
}

class MyQueue {
public:
    stack<int> input;
    stack<int> output;   
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (!output.empty())
        {
            int temp = output.top();
            output.pop();
            return temp;
        }       
        else
        {
            // empty stack
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int temp = output.top();
            output.pop();
            return temp;
        }
    }
    
    int peek() {
        if (!output.empty())
        {
            return output.top();
        }       
        else
        {
            // empty stack
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        return (input.empty() && output.empty());
    }
};

