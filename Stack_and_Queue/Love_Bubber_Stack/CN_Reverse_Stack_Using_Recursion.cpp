#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Reverse_Stack_Using_Recursion";
}

void insertAtBottom(stack<int>& myStack, int x)
{
    // base case
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int element = myStack.top();
    myStack.pop();

    // recursive call
    insertAtBottom(myStack, x);

    myStack.push(element);
}

// TC -> O(N^2)
// SC -> ?
void reverseStack(stack<int> &stack) {
    // base case
    if (stack.empty())
    {
        return;
    }

    int element = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, element);
}