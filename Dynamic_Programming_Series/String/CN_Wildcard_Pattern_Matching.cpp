#include<vector>
#include<iostream>
using namespace std;

int main()
{
    return 0;
}

bool solve(int i, int j, string pattern, string text)
{
    // base case
    if (i < 0 && j < 0) return true;
    if (i < 0 && j >= 0) return false;
    if (j < 0 && i >= 0)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            if (pattern[ii] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if ((pattern[i] == text[j]) || (pattern[i] == '?'))
    {
        return solve(i - 1, j - 1, pattern, text);
    }
    else if ((pattern[i] == '*'))
    {
        return solve(i - 1, j, pattern, text) | solve(i, j - 1, pattern, text);
    }
    else
    {
        return false;
    }
}

// Recursion
// TC -> Exponential
// SC -> O(N + M) -> Auxilary Stack space
bool wildcardMatching_1(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    return solve(n - 1, m - 1, pattern, text);
}

bool solve_1(int i, int j, string pattern, string text)
{
    // base case
    if (i == 0 && j == 0) return true;
    if (i == 0 && j > 0) return false;
    if (j == 0 && i > 0)
    {
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }

    if ((pattern[i-1] == text[j-1]) || (pattern[i-1] == '?'))
    {
        return solve_1(i - 1, j - 1, pattern, text);
    }
    else if ((pattern[i-1] == '*'))
    {
        return solve_1(i - 1, j, pattern, text) | solve_1(i, j - 1, pattern, text);
    }
    else
    {
        return false;
    }
}

// Recursion (1 based indexing)
// TC -> Exponential
// SC -> O(N + M)
bool wildcardMatching_2(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    return solve_1(n, m, pattern, text);
}

int solve_2(int i, int j, string pattern, string text, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0) return 1;
    if (i == 0 && j > 0) return 0;
    if (j == 0 && i > 0)
    {
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                return 0;
            }
        }
        return 1;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if ((pattern[i-1] == text[j-1]) || (pattern[i-1] == '?'))
    {
        return dp[i][j] = solve_2(i - 1, j - 1, pattern, text, dp);
    }
    else if ((pattern[i-1] == '*'))
    {
        return dp[i][j] = solve_2(i - 1, j, pattern, text, dp) | solve_2(i, j - 1, pattern, text, dp);
    }
    else
    {
        return 0;
    }
}

// Memoization
// TC -> O(N * M)
// SC ->  O(N * M) + O(N + M)
bool wildcardMatching_3(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, -1));
    return solve_2(n, m, pattern, text, dp) == 1 ? true : false;
}

// Tabulation
// TC -> O(N * M)
// SC -> O(N * M)
bool wildcardMatching_4(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, 0));

    // base case
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((pattern[i-1] == text[j-1]) || (pattern[i-1] == '?'))
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if ((pattern[i-1] == '*'))
            {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// Space optimization
// TC -> O(N * M)
// SC -> O(M)
bool wildcardMatching_5(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<bool> prev(m + 1, false);

    // base case
    prev[0] = true;
    for (int j = 1; j <= m; j++) prev[j] = false;

    for (int i = 1; i <= n; i++)
    {
        vector<bool> cur(m + 1, false);
        bool flag = true;
        for (int ii = 1; ii <= i; ii++)
        {
            if (pattern[ii - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        cur[0] = flag;

        for (int j = 1; j <= m; j++)
        {
            if ((pattern[i-1] == text[j-1]) || (pattern[i-1] == '?'))
            {
                cur[j] = prev[j - 1];
            }
            else if ((pattern[i-1] == '*'))
            {
                cur[j] = prev[j] | cur[j - 1];
            }
            else
            {
                cur[j] = false;
            }
        }
        prev = cur;
    }

    return prev[m];
}
