#include<iostream>
#include<stack>
using namespace std;

// approch 1
// TC -> O(N)
// SC -> O(N)
string minRemoveToMakeValid(string s) {
    stack<int> stack;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stack.push(i);
        }
        else if (s[i] == ')')
        {
            if (stack.empty())
            {
                s[i] = '#';
            }
            else
            {
                stack.pop();
            }
        }
    }

    while (!stack.empty())
    {
        s[stack.top()] = '#';
        stack.pop();
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

// approach 2
// TC -> O(N)
// SC -> O(1)
string minRemoveToMakeValid(string s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else if (s[i] == ')')
        {
            if (count > 0)
            {
                count--;
            }
            else
            {
                s[i] = '#';
            }
        }
    }

    count = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == ')')
        {
            count++;
        }
        else if (s[i] == '(')
        {
            if (count > 0)
            {
                count--;
            }
            else
            {
                s[i] = '#';
            }
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
        {
            ans.push_back(s[i]);
        }
    }

    return ans;
}