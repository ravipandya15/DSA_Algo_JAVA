#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout << "CN_Valid_Parentheses";
}

bool isValidParenthesis(string expression)
{
    stack<char> st;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            st.push(expression[i]);
        else
        {
            if (st.empty()) return false;
            char ch = st.top();
            if ((expression[i] == ')' && ch == '(') ||
                (expression[i] == '}' && ch == '{') ||
                (expression[i] == ']' && ch == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty()) return true;
    return false;
}