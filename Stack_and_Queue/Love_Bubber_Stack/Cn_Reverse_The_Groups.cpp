#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Reverse_Stack_Using_Recursion";
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    stack<int> result = reverseTheGroups(st, 6, 4);

    while (result.empty())
    {
        cout << result.top() << " " << endl;
        result.pop();
    }
    cout << endl;

    return 0;
}

void reverse(vector<int> &v, int start, int end)
{
    while (start <= end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}

// working
// can also be done using 2 stack
stack<int> reverseTheGroups(stack<int> &s, int n, int k) {

    vector<int> v;
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }

    int a = v.size() / k;
    int j = 0;

    while (a > 0)
    {
        reverse(v, j, j + k - 1);
        j = j + k;
        a--;
    }

    reverse(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}