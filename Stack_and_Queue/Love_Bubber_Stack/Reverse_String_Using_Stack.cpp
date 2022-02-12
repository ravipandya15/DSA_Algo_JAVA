#include<iostream>
#include<stack>
#include<stack>
using namespace std;

int main()
{
    cout << "Reverse_String_Using_Stack";
}

string ReverseString(string str)
{
    stack<char> st;
    string sb = "";
    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
    }

    while (!st.empty())
    {
        sb.push_back(st.top());
        st.pop();
    }

    return sb;
}