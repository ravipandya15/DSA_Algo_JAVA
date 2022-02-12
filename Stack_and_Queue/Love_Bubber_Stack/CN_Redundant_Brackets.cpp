#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Redundant_Brackets";
}

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else
        {
            // it's ')' or lower case letter
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(') // as it's a valid mathematical expressions we definately find '(' bracket
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant) return true;
                st.pop(); //-> to remove '('
            }
        }
    }
    return false;
}