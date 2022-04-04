#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int solve(int i, int j, string s, string t)
{
    // base case
    if (j < 0) return 1;
    if (i < 0) return 0;

    if (s[i] == t[j])
    {
        return solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
    }
    else
    {
        return solve(i - 1, j, s, t);
    }
}

// Recursion
// TC -> Exponential (2^n * 2^m) -> n : len of string s1, m : len of string s2
// SC -> O(N + M)
int numDistinct_1(string s, string t)
{
    int n = s.size();
    int m = t.size();

    return solve(n - 1, m - 1, s, t);
}

int solve_1(int i, int j, string s, string t)
{
    // base case
    if (j == 0) return 1;
    if (i == 0) return 0;

    if (s[i-1] == t[j-1])
    {
        return solve_1(i - 1, j - 1, s, t) + solve_1(i - 1, j, s, t);
    }
    else
    {
        return solve_1(i - 1, j, s, t);
    }
}

// Recursion
// TC -> Exponential (2^n * 2^m) -> n : len of string s1, m : len of string s2
// SC -> O(N + M)
int numDistinct_2(string s, string t)
{
    int n = s.size();
    int m = t.size();

    return solve_1(n, m, s, t);
}

int solve_2(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    // base case
    if (j == 0) return 1;
    if (i == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i-1] == t[j-1])
    {
        return dp[i][j] = solve_2(i - 1, j - 1, s, t, dp) + solve_2(i - 1, j, s, t, dp);
    }
    else
    {
        return dp[i][j] = solve_2(i - 1, j, s, t, dp);
    }
}

// Memoization
// TC -> O(N * M)
// SC -> O(N * M) + O(N + M)
int numDistinct_3(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    return solve_2(n, m, s, t, dp);
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N * M)
int numDistinct_4(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

    // base case
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return (int)dp[n][m];
}

// Space optimization
// TC -> O(N * M)
// SC -> O(M)
int numDistinct_5(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1, 0);

    // base case
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<double> cur(m+1, 0);
        cur[0] = 1;
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
            {
                cur[j] = prev[j - 1] + prev[j];
            }
            else
            {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }

    return (int)prev[m];
}

// 1D array Space optimization - (Only 1D array is required)
// TC -> O(N * M)
// SC -> O(M)
int numDistinct_6(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1, 0);

    // base case
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i-1] == t[j-1])
            {
                prev[j] = prev[j - 1] + prev[j];
            }
            // else
            // {
            //    prev[j] = prev[j];
            // }
        }

    }

    return (int)prev[m];
}