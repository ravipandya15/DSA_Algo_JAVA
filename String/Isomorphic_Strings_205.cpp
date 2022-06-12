#include<iostream>
using namespace std;

int main()
{
    return 0;
}

// approach 1
bool isIsomorphic_1(string s, string t) {
    int n = s.size();
    char seen[128] = {};
    for (int i = 0; i < n; i++)
    {
        if (!seen[s[i]])
        {
            for (char c : seen)
            {
                if (c == t[i]) return false;
            }
            seen[s[i]] = t[i];
        }
        else if (seen[s[i]] != t[i]) return false;
    }
    return true;
}

// approach 2
bool isIsomorphic_2(string s, string t) {
    int n = s.size();
    char map_s[128] = {0};
    char map_t[128] = {0};

    for (int i = 0; i < n; i++)
    {
        if (map_s[s[i]] != map_t[t[i]]) return false;
        map_s[s[i]] = i+1;
        map_t[t[i]] = i+1;
    }
    return true;
}