#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Delete_middle_element_from_stack";
}

void solve(stack<int>&stack, int count, int size)
{
    // base case
    if (count == size/2) 
    {
        stack.pop();
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    solve(stack, count + 1, size);

    stack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack, count, N);
}