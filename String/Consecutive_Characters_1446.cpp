#include<vector>
#include<iostream>
using namespace std;

int maxPower(string s) {
    int x = 1, ans = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i-1])
        {
            x++;
        }
        else
        {
            ans = max(ans, x);
            x = 1;
        }
    }
    ans = max(ans, x);
    return ans;
}