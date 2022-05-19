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
string removeDuplicates(string s, int k) {
    int n = s.size();
    if (n < k) return s;

    stack<pair<char, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top().first != s[i])
        {
            st.push({s[i], 1});
        }
        else
        {
            auto prev = st.top();
            st.pop();

            st.push({s[i], prev.second + 1});
        }
        if (st.top().second == k) st.pop();
    }

    string result;

    while (!st.empty())
    {
        auto prev = st.top();
        st.pop();

        while (prev.second > 0)
        {
            result.push_back(prev.first);
            prev.second--;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}