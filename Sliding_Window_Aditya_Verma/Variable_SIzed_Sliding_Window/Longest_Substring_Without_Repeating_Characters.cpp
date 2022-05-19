#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

// best approach
// TC -> O(N)
int longestSubstrDistinctChars (string S)
{
    int n = S.size();
    unordered_map<char, int> map;
    int l = 0, r = 0, len = 0;
    
    while (r < n)
    {
        if (map.find(S[r]) != map.end())
        {
            l = max(l, map[S[r]] + 1);
            map[S[r]] = r;
        }
        else
        {
            map[S[r]] = r;
        }
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

// best approach
// TC -> O(N)
int longestSubstrDistinctChars (string S)
{
    int n = S.size();
    unordered_map<char, int> map;
    int l = 0, r = 0, len = 0;
    
    while (r < n)
    {
        if (map.find(S[r]) == map.end())
        {
            map[S[r]] = r;
        }
        else
        {
            l = max(l, map[S[r]] + 1);
            map[S[r]] = r;
        }
        len = max(len, r - l + 1);
        r++;
    }
    return len;
}

// TC -> O(2N)
int lengthOfLongestSubstring(string s) {
    set<char> st;
    int i = 0;
    int j = 0;
    int n = s.size();
    int maxi = 0;

    while (j < n)
    {
        // calculation
        if (st.find(s[j]) == st.end())
        {
            st.insert(s[j]);
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else
        {
            while (i < j && s[i] != s[j])
            {
                st.erase(s[i]);
                i++;
            }
            if (i < j && s[i] == s[j])
            {
                st.erase(s[i]);
                i++;
            }
        }
    }
    return maxi;
}