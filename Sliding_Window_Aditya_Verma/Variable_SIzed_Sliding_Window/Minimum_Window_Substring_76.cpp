#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    return 0;
}

string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    unordered_map<char, int> mp;
    for (int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }

    int count = mp.size();

    int i = 0, j = 0;
    int minI = 0, minJ = 0;
    int minLength = 0;
    int n = s.size();

    while (j < n)
    {
        // calculation
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        if (count > 0)
        {
            j++;
        }
        else if (count == 0)
        {
            while (count == 0)
            {
                if (minLength == 0 || j - i + 1 < minLength)
                {
                    minI = i, minJ = j;
                    minLength = minJ - minI + 1;
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
    }

    return s.substr(minI, minLength);
}