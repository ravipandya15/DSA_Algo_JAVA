#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Insert_An_Element_At_Its_Bottom_In_A_Given_Stack";
}

void solve(stack<int>& myStack, int x)
{
    // base case
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int element = myStack.top();
    myStack.pop();

    // recursive call
    solve(myStack, x);

    myStack.push(element);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}