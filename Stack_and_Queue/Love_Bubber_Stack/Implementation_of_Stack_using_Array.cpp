#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "Implementation_of_Stack_using_Array";
}

class Stack
{
    public:
        int size;
        int top;
        int* arr;

    Stack(int s)
    {
        this->size = s;
        arr = new int[this->size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1) // or top < size
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};