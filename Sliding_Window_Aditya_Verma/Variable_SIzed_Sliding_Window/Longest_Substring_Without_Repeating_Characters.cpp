#include<iostream>
#include<vector>
#include<set>
using namespace std;

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
            j++;
        }
        else
        {
            while (s[i] != s[j])
            {
                st.erase(s[i]);
                i++;
            }
        }
        maxi = max(maxi, j - i + 1);
    }
    return maxi;
}