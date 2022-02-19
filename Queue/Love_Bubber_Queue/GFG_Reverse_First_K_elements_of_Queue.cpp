#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int t = q.size() - k;

    while (t--)
    {
        int data = q.front();
        q.pop();
        q.push(data);
    }

    return q;
}