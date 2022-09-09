#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

// LEETCODE

#include<algorithm>

class Solution {
public:
    bool static comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    
    bool checkPossible(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1) return false;

        int first = 0;
        int second = 0;

        while (first < s1.size()) // first < s1.size() && second < s2.size()
        {
            if (s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else 
            {
                first++;
            }
        }

        if (first == s1.size() && second == s2.size()) return true; // if (second == s2.size()) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(arr.begin(), arr.end(), comp);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

// Coding Ninjas

bool static comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

class comparator
{
    public:
    bool operator()(string &s1, string &s2)
    {
        return s2.size() < s1.size();
    }
};

// here s1 is always longer than s2


// commented code also giving correct answer. and as per my understanding 
//normal code is wrong and commented code is works fine. submitted on CN  



bool checkPossible(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1) return false;

    int first = 0;
    int second = 0;

    while (first < s1.size()) // first < s1.size() && second < s2.size()
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else 
        {
            first++;
        }
    }

    if (first == s1.size() && second == s2.size()) return true; // if (second == s2.size()) return true;
    return false;
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}