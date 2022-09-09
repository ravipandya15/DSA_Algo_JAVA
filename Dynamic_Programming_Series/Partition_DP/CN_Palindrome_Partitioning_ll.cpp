#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// #include<bits/stdc++.h>

int main()
{
    return 0;
}

bool isPalindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string &str, vector<int> &dp)
{
    // base case
    if (i == n) return 0;
    int minCost = INT_MAX;
    if (dp[i] != -1) return dp[i];

    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + solve(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[i] = minCost;
}

// Memoization
// TC -> O(N^2)
// SC -> O(N) + O(N)
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n, -1);
    return solve(0, n, str, dp) - 1;
}

// Tabulation
// TC -> O(N^2)
// SC -> O(N)
int palindromePartitioning(string str) {
    int n = str.size();
    vector<int> dp(n + 1, 0);

    // base case
    dp[n] = 0;
    
    for (int i = n-1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }

        dp[i] = minCost;
    }
    return dp[0] - 1;
}