#include<iostream>
using namespace std;

int main()
{
    cout << "125 Valid Palindrome";
    return 0;
}

char ConvertToLower(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || ch >= '0' && ch <= '9')
        return ch;
    else
    {
        return (char)(ch - 'A' + 'a');
    }
}

bool Check(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    else
        return false;
}

static bool CheckPalindrome(string str)
{
    string s;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (Check(str[i])) s.push_back(str[i]);
    }

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = ConvertToLower(s[i]);
    }

    int l = 0, r = s.length()-1;
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        else
        {
            l++;
            r--;
        }
    }
    return true;
}