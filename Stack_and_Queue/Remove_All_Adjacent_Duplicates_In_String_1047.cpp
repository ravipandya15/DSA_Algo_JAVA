#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// TC -> O(N)
// SC -> O(N)
string removeDuplicates(string s) {
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }

    string result;

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}