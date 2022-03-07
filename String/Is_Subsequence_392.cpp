#include<iostream>
using namespace std;

int main()
{
    return 0;
}

bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    int i = 0;
    for (int j = 0; j < t.size(); j++)
    {
        if (s[i] == t[j])
        {
            i++;
        }

        if (i == s.size())
        {
            return true;
        }
    }

    return false;
}