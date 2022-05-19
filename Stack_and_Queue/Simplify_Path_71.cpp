#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

string simplifyPath(string path) {
    stack<string> st;
    int n = path.size();

    for (int i = 0; i < n; i++)
    {
        if (path[i] == '/') continue;

        string temp = "";
        while (i < n && path[i] != '/')
        {
            temp = temp + path[i];
            i++;
        }

        if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (temp == ".") continue;
        else
        {
            st.push(temp);
        }
    }

    string res = "";

    while (!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }

    if (res.size() == 0) res = "/";

    return res;
}