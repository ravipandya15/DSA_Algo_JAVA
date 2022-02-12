#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Sort_a_Stack";
}

void sortInsert(stack<int> &stack, int num)
{
    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }

    int element = stack.top();
    stack.pop();

    // recursive call
    sortInsert(stack, num);

    stack.push(element);
}

void sortStack(stack<int> &stack)
{
	if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortInsert(stack, num);
}