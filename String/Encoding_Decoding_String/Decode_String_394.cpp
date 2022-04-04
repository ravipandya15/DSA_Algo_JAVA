#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

// also in GFG

string repeat(string s, int num)
{
    string ans = "";
    for (int i = 0; i < num; i++)
    {
        ans = ans + s;
    }
    return ans;
}

string decodeString(string s) {
    int curNum = 0;
    string curString = "";
    stack<int> stInt;
    stack<string> stString;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            stInt.push(curNum);
            stString.push(curString);
            curNum = 0;
            curString = "";
        }
        else if (s[i] == ']')
        {
            int prevNum = stInt.top();
            string prevString = stString.top();
            stInt.pop();
            stString.pop();
            curString = prevString + repeat(curString, prevNum);
        }
        else if (isdigit(s[i]))
        {
            curNum = curNum * 10 + (s[i] - '0');
        }
        else
        {
            curString = curString + s[i];
        }
    }

    return curString;
}