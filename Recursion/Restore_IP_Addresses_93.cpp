#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    return 0;
}

bool isValid(string s)
{
    if (s[0] == '0') return false;
    int num = stoi(s);
    return (num <= 255);
}

void helper(int index, int partition, string s, string ans, vector<string> &res)
{
    // base case
    if (index == s.length() || partition == 4)
    {
        if (index == s.length() && partition == 4)
        {
            res.push_back(ans.substr(0, ans.size() - 1));
        }
        return;
    }

    helper(index + 1, partition + 1, s, ans + s[index] + ".", res);
    if (index + 1 < s.length() && isValid(s.substr(index, 2)))
    {
        helper(index + 2, partition + 1, s, ans + s.substr(index, 2) + ".", res);
    }
    
    if (index + 2 < s.length() && isValid(s.substr(index, 3)))
    {
        helper(index + 3, partition + 1, s, ans + s.substr(index, 3) + ".", res);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string ans = "";
    helper(0, 0, s, ans, res);
    return res;
}