#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestKSubstr(string s, int k) {
    unordered_map<char, int> mp;

    int i = 0, j = 0;
    int maxi = -1;
    int n = s.size();

    while (j < n)
    {
        // calculation
        mp[s[j]]++;

        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            // ans
            maxi = max(maxi, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    return maxi;
}