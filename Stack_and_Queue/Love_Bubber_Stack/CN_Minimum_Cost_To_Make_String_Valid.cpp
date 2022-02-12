#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Minimum_Cost_To_Make_String_Valid";
}

// TC -> O(N)
// SC -> O(N)
int findMinimumCost(string str) {
    // odd length
    if (str.length() % 2 == 1) return -1;

    // if any valid paranthesis found remove it
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {// closing bracket
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // stack contains invalid characters
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{') b++;
        else if (st.top() == '}') a++;
        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}