#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_N_Stacks_In_An_Array";
}

class NStack
{
public:
    int* arr;
    int* top;
    int* next;
    int freespot;
    int n, s;
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        
        // initialize top
        for (int i = 0; i < N; i++) top[i] = -1;

        // initialize next
        for (int i = 0; i < S; i++) next[i] = i+1;
        next[S-1] = -1;

        // initialize freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow;
        if (freespot == -1) return false;

        // find index;
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element into array
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if (top[m-1] == -1) return -1;

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};