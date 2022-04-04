#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// approach 1
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();

    for (int i = 0; i < strs[0].length(); i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < n; j++)
        {
            if (i == strs[j].length() || strs[j][i] != c)
            {
                return strs[0].substr(0, i);
            }
        }

    }
    return strs[0];
}

string commonPrefix(string left, string right)
{
    int minLength = min(left.length(), right.length());

    for (int i = 0; i < minLength; i++)
    {
        if (left[i] != right[i])
        {
            return left.substr(0, i);
        }
    }

    return left.substr(0, minLength);
}
string longestcommonPrefix(vector<string>& strs, int l, int r)
{
    if (l == r)
    {
        return strs[l];
    }
    else
    {
        int mid = l + (r-l)/2;
        string left = longestcommonPrefix(strs, l, mid);
        string right = longestcommonPrefix(strs, mid+1, r);
        return commonPrefix(left, right);
    }
}

// approach 2
// divide and conquer
string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
    {
        return "";
    }

    return longestcommonPrefix(strs, 0, strs.size() - 1);
}

