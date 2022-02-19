#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

queue<int> rev(queue<int> q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
} 