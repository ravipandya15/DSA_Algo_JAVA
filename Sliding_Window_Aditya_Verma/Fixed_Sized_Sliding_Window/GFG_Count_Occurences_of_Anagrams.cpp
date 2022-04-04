#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

int search(string pat, string txt) {
    unordered_map<char, int> mp;
    int k = pat.size();
    int n = txt.size();
    int i = 0, j = 0;
    int count = 0, ans = 0;

    for (int i = 0; i < k; i++)
    {
        if (mp.find(pat[i]) == mp.end())
        {
            count++;
        }
        mp[pat[i]]++;
    }
    i=0;

    while (j < n)
    {
        // calculations
        if (mp.find(txt[j]) != mp.end())
        {
            mp[txt[j]]--;
            if (mp[txt[j]] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            // find ans
            if (count == 0)
            {
                ans++;
            }

            // calculation
            if (mp.find(txt[i]) != mp.end())
            {
                mp[txt[i]]++;
                if (mp[txt[i]] == 1)
                {
                    count++;
                }
            }

            i++;
            j++;
        }
    }

    return ans;
}